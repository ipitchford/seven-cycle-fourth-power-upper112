"""Check bundle bytes and elementary controls; --full replays the main theorem."""
import argparse
import hashlib
from itertools import combinations, product
import json
from pathlib import Path
import subprocess
import sys
import zipfile

def need(ok, message):
    if not ok:
        raise ValueError(message)

def digest(path):
    h=hashlib.sha256()
    with path.open('rb') as f:
        for block in iter(lambda:f.read(1024*1024),b''):h.update(block)
    return h.hexdigest()

def check_words(words):
    need(len(words)==108, 'lower witness size')
    need(all(len(v)==4 and all(type(x)is int and 0<=x<7 for x in v) for v in words),'word domain')
    words=[tuple(v) for v in words]
    need(len(set(words))==108,'duplicate word')
    need(all(any((a-b)%7 not in (0,1,6) for a,b in zip(u,v)) for u,v in combinations(words,2)), 'confusable pair')
    return 5778

def check(root):
    listed=set()
    for line in (root/'MANIFEST.sha256').read_text().splitlines():
        sha,name=line.split('  ',1)
        rel=Path(name)
        need(not rel.is_absolute() and '..' not in rel.parts,'unsafe manifest path')
        need(name not in listed,'duplicate manifest member');listed.add(name)
        p=root/rel
        need(p.is_file() and not p.is_symlink() and digest(p)==sha,'file mismatch: '+name)
    actual={p.relative_to(root).as_posix() for p in root.rglob('*') if p.is_file() and p.name!='MANIFEST.sha256'}
    need(listed==actual,'manifest coverage')
    witness=json.loads((root/'data/witness108.json').read_text())['words']
    pairs=check_words(witness)
    counts=[0,0]
    for a in product(range(14,20),repeat=7):
        if sum(a)!=113:continue
        bands=[a[i]+a[(i+1)%7] for i in range(7)]
        if max(bands)>33:continue
        heavy=[i for i,b in enumerate(bands) if b==33]
        nonadj=any((i-j)%7 in (2,3,4,5) for i,j in combinations(heavy,2))
        counts[0 if nonadj else 1]+=1
    need(counts==[455,7],'normalization split')
    main=root/'evidence/c7-fourth-power-upper112.zip'
    need(digest(main)=='a9a54be2206c5e3fdf9059f687b593fb4ccb7506676edc36ce732ec2109ca347','main theorem archive identity')
    return {'status':'PASS_BUNDLE_BYTES_LOWER_WITNESS_AND_NORMALIZATION',
            'files':len(listed),'lower_pairs':pairs,'profiles':counts,
            'scope':'Does not rerun the long upper-bound proof. Use --full for that.'}

def extract_safe(archive,out):
    with zipfile.ZipFile(archive) as z:
        for item in z.infolist():
            p=Path(item.filename)
            need(not p.is_absolute() and '..' not in p.parts,'unsafe ZIP path')
            need((item.external_attr>>16)&0o170000 != 0o120000,'ZIP symlink')
        z.extractall(out)

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--full',action='store_true')
    ap.add_argument('--work-dir',type=Path)
    args=ap.parse_args()
    root=Path(__file__).resolve().parent
    print(json.dumps(check(root)),flush=True)
    if args.full:
        need(args.work_dir is not None,'--full requires a new --work-dir')
        out=args.work_dir.resolve()
        need(not out.exists() and root not in out.parents,'scratch must be new and outside bundle')
        out.mkdir(parents=True)
        extract_safe(root/'evidence/c7-fourth-power-upper112.zip',out)
        package=out/'c7-fourth-power-upper112'
        subprocess.run([sys.executable,'-B',str(package/'verify.py'),'--bundle',str(package),
                        '--out',str(out/'main-replay')],check=True)

if __name__=='__main__':main()
