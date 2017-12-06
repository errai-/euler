from collections import OrderedDict
from operator import itemgetter

primes = [2,3,5,7,11,13]

def isprime(num):
    if num==1:
        return False
    elif all(num%i!=0 for i in primes[:primes.index(next(x for x in primes if x>num**0.5))]):
        return True
    else:
        return False

for num in range(15,200,2):
    if isprime(num):
        primes = primes + [num]

# Warning: does not handle 1 or uneven numbers
def primefacs(num):
    primeidx = 0
    results = dict()
    while num!=1 and primeidx<len(primes):
        cprime = primes[primeidx]
        primeidx += 1
        if num%cprime==0:
            results[cprime] = 0
            while num%cprime==0:
                num /= cprime
                results[cprime] += 1
    return results

steps = {1:[1]}
for k in range(2,201):
    facs = primefacs(k)
    res = []
    if len(facs)==1 and facs.values()[0]==1: # Prime keys
        if len(steps[k-1])>0:
            res = list(steps[k-1])+[k]
    else: # Non-prime keys
        maxval = 0
        maxkey = 0
        news = []
        ofacs = OrderedDict(sorted(facs.items(), key=lambda t: t[0],reverse=False))
        multiplier = 1
        while len(ofacs)>0:
            more = ofacs.popitem(False)
            whole = more[0]**more[1]
            if whole in steps:
                addition = list(steps[whole])
            else:
                addition = list(steps[whole/more[0]])
                addition += [x*addition[-1] for x in list(steps[more[0]])[1:]]
            for a in range(0,len(addition)):
                addition[a] *= multiplier
            if (len(res)>0 and res[-1]==addition[0]):
                addition = addition[1:]
            res += addition
            multiplier *= whole
    limit = k//2
    minlen = len(res)
    for j in range(1,limit+1):
        i = k-j
        li = list(steps[i])
        lj = list(steps[j])
        for vali in li:
            if vali in lj:
                lj.remove(vali)
        tmplen = len(lj)+len(li)+1
        if tmplen<minlen:
            print(k,"juu!")
            res = li+lj+[k]
            minlen = tmplen
    steps[k] = res
sumall = 0
for a in steps:
    print(a,steps[a])
    sumall += len(steps[a])-1
print(sumall)
