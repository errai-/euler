P = -9
Q = -4
K = -14
R = -20
S = -9
L = -28

#P = 4
#Q = -9
#K = -14
#R = -9
#S = 20
#L = 28
prevs = []
prevs.append([0,1])
prevs.append([0,-1])
prevs.append([2,7])
prevs.append([2,-7])
prevs.append([5,-14])
prevs.append([5,14])
prevs.append([21,-50])
prevs.append([21,50])

res = []
yvals = dict()

for pruv in prevs:
    nprev = pruv[0]
    yprev = pruv[1]

    for i in range(30):
        if nprev>0 and nprev not in res:
            res.append(nprev)
            yvals[nprev] = yprev
        n = P*nprev+Q*yprev+K
        y = R*nprev+S*yprev+L
        nprev = n
        yprev = y
for i in sorted(res)[:30]:
    print(i,yvals[i])
print(sum(sorted(res)[:30]))
