"""Integer-only box certificates over cardinality-filtered Boolean cubes.

Cube-cover completeness is an external dependency bound by SHA256. This replay
does not trust numerical optimization or any claimed coverage/minimum value.
"""
import argparse, hashlib, itertools, json, random, time
from pathlib import Path

FULL = (1 << 66) - 1
ROWS = [(axes, starts, cap) for k, cap in ((1,33),(2,10),(3,3),(4,1))
        for axes in itertools.combinations(range(4), k)
        for starts in itertools.product(range(7), repeat=k)]

def need(ok, message):
    if not ok:
        raise ValueError(message)

def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def point(v):
    return (v//343, v//49%7, v//7%7, v%7)

def cube_minimum(cube, costs):
    """Return exact minimum delta cost and an attaining 66-bit assignment."""
    mask, on = cube['mask'], cube['on']
    need(type(mask) is int and type(on) is int and 0 <= mask <= FULL
         and 0 <= on <= FULL and not(on & ~mask), 'cube syntax')
    need(len(costs) == 66 and all(type(c) is int for c in costs), 'costs')
    value = sum(costs[j] for j in range(66) if on >> j & 1)
    witness = on
    for start in (0,33):
        fixed = sum(on >> j & 1 for j in range(start,start+33))
        free = sorted((costs[j], j) for j in range(start,start+33) if not(mask >> j & 1))
        low, high = max(0,14-fixed), min(len(free),19-fixed)
        need(low <= high, 'cardinality-infeasible cube')
        prefix = [0]
        for cost, _ in free:
            prefix.append(prefix[-1]+cost)
        best = min(range(low,high+1), key=lambda k:(prefix[k],k))
        value += prefix[best]
        for _,j in free[:best]:
            witness |= 1 << j
    need(witness & mask == on and all(14 <= ((witness >> start)&((1<<33)-1)).bit_count() <= 19 for start in (0,33)), 'minimum witness')
    need(value == sum(costs[j] for j in range(66) if witness >> j & 1), 'minimum objective')
    return value,witness

def geometry(first, second, multipliers):
    for band in (first,second):
        need(len(band)==33 and all(type(v) is int and 0<=v<343 for v in band)
             and band==sorted(set(band)), 'independent band syntax')
        need(all(any((x-y)%7 not in (0,1,6) for x,y in zip(point(a),point(b)))
                 for a,b in itertools.combinations(band,2)), 'band independence')
    weights = [0]*2401
    capacity = 0
    seen = set()
    for record in multipliers:
        need(type(record) is list and len(record)==2, 'box record')
        i,y = record
        need(type(i) is int and 0<=i<len(ROWS) and i not in seen
             and type(y) is int and y>0, 'box coefficient')
        seen.add(i)
        axes,starts,cap = ROWS[i]
        # Direct physical membership, independent of discovery's incidence API.
        for v in range(2401):
            p = point(v)
            if all(p[a] in (s,(s+1)%7) for a,s in zip(axes,starts)):
                weights[v] += y
        capacity += cap*y
    mapping = [[343+v,v] for v in first]+[[1372+v,1029+v] for v in second]
    return weights,capacity,mapping

def evaluate(cert):
    need(cert['distance']==3 and type(cert['distance']) is int, 'distance')
    D=cert['denominator']
    need(type(D) is int and D>0, 'denominator')
    cubes=cert['cubes']
    need(type(cubes) is list and len(cubes)>0, 'nonempty cube cover')
    need([(c['mask'],c['on']) for c in cubes]==sorted(set((c['mask'],c['on']) for c in cubes)), 'canonical cubes')
    W,C,mapping=geometry(cert['first'],cert['second'],cert['box_multipliers'])
    need(mapping==cert['variables_off_on_physical_vertex'], 'physical allocation map')
    base=sum(W[off] for off,on in mapping)
    delta=[W[on]-W[off] for off,on in mapping]
    minima=[cube_minimum(c,delta) for c in cubes]
    best=min(range(len(cubes)), key=lambda i:(minima[i][0],i))
    minimum=base+minima[best][0]
    free=[343*layer+v for layer in (2,5,6) for v in range(343)]
    repair=sum(max(0,D-W[v]) for v in free)
    numerator=66*D+C-minimum+repair
    return {'capacity_cost':C,'fixed_weight_minimum':minimum,'unit_repair_total':repair,
            'numerator':numerator,'denominator':D,'conditional_integer_upper':numerator//D,
            'minimum_cube':best,'minimum_assignment':minima[best][1],
            'cubes_checked':len(cubes),'free_vertices_checked':len(free)}

def replay(cert):
    fixture=cert['fixture_dependency']
    fixture_path=Path(fixture['path'])
    need(sha(fixture_path)==fixture['sha256'], 'fixture dependency hash')
    need(list(map(int,fixture_path.read_text().split()))==[3]+cert['first']+cert['second'], 'fixture physical identity')
    dependency=cert['cube_cover_dependency']
    path=Path(dependency['path'])
    need(sha(path)==dependency['sha256'], 'cube dependency hash')
    cover=json.loads(path.read_text())
    need(cover['status']=='COMPLETE_JOIN_CUBE_COVER_ONLY' and cover['distance']==3
         and cover['models_enumerated']==0, 'cube completeness status')
    need(cover['cubes']==cert['cubes'] and cover['variables_off_on_physical_vertex']==cert['variables_off_on_physical_vertex'], 'complete cube binding')
    result=evaluate(cert)
    need(cert['result']==result, 'claimed bound mismatch')
    return result

def controls():
    rng=random.Random(20261005)
    count=0
    # Exhaustive checks with 10 free coordinates and signed weights.
    for _ in range(40):
        free=sorted(rng.sample(range(33),5)+rng.sample(range(33,66),5))
        mask=FULL ^ sum(1<<j for j in free)
        on=0
        for start in (0,33):
            fixed=[j for j in range(start,start+33) if mask>>j&1]
            on |= sum(1<<j for j in rng.sample(fixed,rng.randrange(12,20)))
        costs=[rng.randrange(-100,101) for _ in range(66)]
        values=[]
        for bits in range(1<<len(free)):
            assignment=on | sum(1<<j for i,j in enumerate(free) if bits>>i&1)
            if all(14<=((assignment>>start)&((1<<33)-1)).bit_count()<=19 for start in (0,33)):
                values.append(sum(costs[j] for j in range(66) if assignment>>j&1))
        need(values and cube_minimum({'mask':mask,'on':on},costs)[0]==min(values), 'exhaustive oracle control')
        count+=1
    # All-free cubes, including large integer costs and ties, checked by a
    # separate count-indexed dynamic program, without sorting costs.
    for _ in range(20):
        costs=[rng.randrange(-10**30,10**30) if _ else 0 for j in range(66)]
        answer=0
        for start in (0,33):
            dp={0:0}
            for cost in costs[start:start+33]:
                nxt=dp.copy()
                for n,v in dp.items():
                    nxt[n+1]=min(nxt.get(n+1,10**40),v+cost)
                dp=nxt
            answer+=min(dp[n] for n in range(14,20))
        need(cube_minimum({'mask':0,'on':0},costs)[0]==answer, 'dynamic program oracle control')
        count+=1
    return {'status':'PASS_EXACT_CUBE_MINIMUM_CONTROLS','cases':count}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('certificate',nargs='?',type=Path);ap.add_argument('--controls',action='store_true');args=ap.parse_args()
    start=time.monotonic()
    if args.controls:
        result=controls()
    else:
        need(args.certificate is not None,'certificate required')
        result={'status':'PASS_EXACT_CUBE_PACKING_CERTIFICATE','result':replay(json.loads(args.certificate.read_text())),'certificate_sha256':sha(args.certificate)}
    result.update(seconds=time.monotonic()-start,verifier_sha256=sha(__file__))
    print(json.dumps(result,indent=2))

if __name__=='__main__':
    main()
