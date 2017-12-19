from collections import OrderedDict
from operator import itemgetter

primes = [2,3,5,7,11,13]
uplim = 120000

def isprime(num):
    if num==1:
        return False
    elif all(num%i!=0 for i in primes[:primes.index(next(x for x in primes if x>num**0.5))]):
        return True
    else:
        return False

for num in range(15,uplim,2):
    if isprime(num):
        primes = primes + [num]

# Warning: does not handle 1 or uneven numbers
def primefacs(num):
    primeidx = 0
    result = []
    multi = 1
    while num!=1 and primeidx<len(primes):
        cprime = primes[primeidx]
        primeidx += 1
        if num%cprime==0:
            result.append(cprime)
            multi *= cprime
            while num%cprime==0:
                num /= cprime
    result = [result,multi]
    return result

results = dict()
for i in range(1,uplim):
    results[i] = primefacs(i)

def commons(l1,l2):
    bad2 = False
    for a in l1:
        if a in l2:
            bad2 = True
            break
    return bad2

res = OrderedDict(sorted(results.items(), key=lambda t: t[1][1]))
print(res)
cvals = []
cval = 3
for cval in res:
    halfc = cval/2
    radc = cval/res[cval][1]
    halfcj = radc/2
    for aval in res:
        if res[aval][1]>halfcj:
            break
        if aval==cval:
            continue
        if aval>halfc:
            continue
        bval = cval-aval
        if bval<=aval:
            continue
        if commons(res[aval][0],res[bval][0]):
            continue
        radab = res[aval][1]*res[bval][1]
        if radab<radc:
            cvals.append(cval)
            print(aval,bval,cval)
print(cvals,len(cvals),sum(cvals))
