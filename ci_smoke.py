"""Repository CI: lower witness and elementary normalization, not the upper proof."""
import json
from pathlib import Path
from itertools import product,combinations
from verify_bundle import check_words,need
root=Path(__file__).resolve().parent
words=json.loads((root/'data/witness108.json').read_text())['words']
need(check_words(words)==5778,'lower witness')
counts=[0,0]
for a in product(range(14,20),repeat=7):
    if sum(a)!=113:continue
    bands=[a[i]+a[(i+1)%7] for i in range(7)]
    if max(bands)>33:continue
    z=[i for i,b in enumerate(bands) if b==33]
    nonadj=any((i-j)%7 in (2,3,4,5) for i,j in combinations(z,2))
    counts[0 if nonadj else 1]+=1
need(counts==[455,7],'exhaustive normalization')
for bad in ([words[0]]+words[:-1],[words[0],[(words[0][0]+1)%7,*words[0][1:]]]+words[2:]):
    try:check_words(bad)
    except ValueError:pass
    else:raise ValueError('Corrupted lower witness accepted')
print(json.dumps({'status':'PASS_REPOSITORY_SMOKE_ONLY','pairs':5778,'profiles':counts,'negative_controls':2,'scope':'Does not replay the upper112 or auxiliary certificates; download the versioned bundle and follow REPRODUCE.md.'}))
