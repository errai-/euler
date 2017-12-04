# Just brute force; this would be solved by binomial factors

rmsum = 0

for i in range(3,1001):
    n1 = i-1
    n2 = i+1
    sn1 = 1
    sn2 = 1
    divis = i*i
    rmax = 0
    for n in range(0,100000):
        sn1 *= n1
        sn2 *= n2
        rnow = (sn1+sn2)%divis
        if rnow>rmax:
            rmax=rnow
    rmsum += rmax
print(rmsum)
