from collections import defaultdict
import bisect
from sets import Set

mappings = defaultdict(list)
caseno = 0

def adduntil(mp,limit):
    while mappings[mp][-1]<limit:
        mappings[mp].append(mappings[mp][-1]*mp)

trials = []
limit = 500000000000000
for i in range(2,int(limit**0.5)):
    now = pow(i,2)
    while now < limit:
        if now>9:
            trials.append(now)
        now *= i

trials = sorted(set(trials))

for num in trials:
    sumnos = sum(map(int,list(str(num))))
    if sumnos==1:
        continue
    if sumnos not in mappings:
        mappings[sumnos] = [sumnos]
    adduntil(sumnos,num)
    if num in mappings[sumnos]:
        caseno += 1
        print(caseno,num)

print(len(mappings))
