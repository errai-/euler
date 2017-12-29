P = 3
Q = 2
K = 0
R = 4
S = 3
L = 0

#P = 4
#Q = -9
#K = -14
#R = -9
#S = 20
#L = 28
prevs = []
prevs.append([1,1])
prevs.append([-1,-1])
prevs.append([1,-1])
prevs.append([-1,1])

res = []
yvals = dict()

for pruv in prevs:
    nprev = pruv[0]
    yprev = pruv[1]

    for i in range(2,30):
        if nprev>1 and nprev not in res:
            res.append(nprev)
            yvals[nprev] = yprev
        n = P*nprev+Q*yprev+K
        y = R*nprev+S*yprev+L
        nprev = n
        yprev = y
goods = sorted(res)
for i in goods:
    print(i,yvals[i],(1+yvals[i])/(i**2-1.0),100000000*(1+yvals[i])/(i**2-1.0))
print(len(goods))
