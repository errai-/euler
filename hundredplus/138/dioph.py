# 5n^2 +4n + 1 - L^2
#P = -9
#Q = -4
#K = -4
#R = -20
#S = -9
#L = -8
P = -9
Q = 4
K = -4
R = 20
S = -9
L = 8

prevs = []
prevs.append([0,1])
prevs.append([0,-1])
prevs.append([136,305])
prevs.append([136,-305])
prevs.append([43920,98209])
prevs.append([43920,-98209])

res = []
yvals = dict()

for pruv in prevs:
    nprev = pruv[0]
    yprev = pruv[1]

    for i in range(30):
        if nprev>0 and nprev not in res:
            res.append(nprev)
            yvals[nprev] = abs(yprev)
        n = P*nprev+Q*yprev+K
        y = R*nprev+S*yprev+L
        nprev = n
        yprev = y

#P = -9
#Q = -4
#K = 4
#R = -20
#S = -9
#L = 8
P = -9
Q = 4
K = 4
R = 20
S = -9
L = -8

prevs = []
prevs.append([0,1])
prevs.append([0,-1])
prevs.append([8,17])
prevs.append([8,-17])
prevs.append([2448,5473])
prevs.append([2448,-5473])

for pruv in prevs:
    nprev = pruv[0]
    yprev = pruv[1]

    for i in range(30):
        if nprev>0 and nprev not in res:
            res.append(nprev)
            yvals[nprev] = abs(yprev)
        n = P*nprev+Q*yprev+K
        y = R*nprev+S*yprev+L
        nprev = n
        yprev = y


for i in sorted(res)[:30]:
    print(i,yvals[i])
print(sum(map(lambda l : yvals[l],sorted(res)[:12])))
