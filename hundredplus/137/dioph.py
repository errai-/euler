
P = -9
Q = -4
K = -2
R = -20
S = -9
L = -4
prevs = [[-1,2],[-1,-2],[0,-1],[2,5],[2,-5]]

res = []

for pruv in prevs:
    nprev = pruv[0]
    yprev = pruv[1]

    for i in range(30):
        if nprev>0 and nprev not in res:
            res.append(nprev)
        n = P*nprev+Q*yprev+K
        y = R*nprev+S*yprev+L
        nprev = n
        yprev = y
for i in sorted(res):
    print(i)
