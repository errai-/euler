from collections import defaultdict


mappings = defaultdict(list)
caseno = 0

def adduntil(mp,limit):
    while mappings[mp][-1]<limit:
        mappings[mp].append(mappings[mp][-1]*mp)

for num in range(10,999):
    sumnos = sum(map(int,list(str(num))))
    if sumnos==1:
        continue
    if sumnos not in mappings:
        mappings[sumnos] = [sumnos]
    adduntil(sumnos,num)
    if num in mappings[sumnos]:
        caseno += 1
        print(caseno,num)

print(mappings)
print(len(mappings))
