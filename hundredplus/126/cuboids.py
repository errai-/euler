sizelim = 20000

flats = dict()
def flat(n):
    if n in flats:
        return flats[n]
    if n<2:
        corners[n] = 0
        return 0
    else:
        return n-1

corners = dict()
def corner(n):
    if n not in corners:
        if n<3:
            corners[n] = 0
        else:
            corners[n] = (n-2)*(n-1)/2
    return corners[n]

def blockcount(x,y,z):
    base = 2*(x*y+y*z+x*z)
    side = 4*(x+y+z)
    total = 0
    layer = 0
    while total<=sizelim:
        layer += 1
        total = base+8*corner(layer)+side*flat(layer)
        yield [layer,total]

CNinLayer = dict()
for z in range(1,sizelim+1):
    for y in range(1,z+1):
        toobigat1 = False
        for x in range(1,y+1):
            if 2*(x*y+y*z+x*z)>sizelim:
                if x==1:
                    toobigat1 = True
                break
            cuboid = blockcount(x,y,z)
            for layer in cuboid:
                if not layer[1] in CNinLayer:
                    CNinLayer[layer[1]] = 1
                else:
                    CNinLayer[layer[1]] += 1
        if toobigat1:
            break

for a in CNinLayer:
    if CNinLayer[a]==1000:
        print(a,CNinLayer[a])
