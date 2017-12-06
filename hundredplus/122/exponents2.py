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

steps = {1:0}
for k in range(2,201):
    resprev = [[1]]
    ready = False
    while not ready:
        resnow = []
        for i in resprev:
            for j in i:
                nexts = i[-1]+j
                if nexts>k:
                    break
                resnow.append(list(i)+[nexts])
                if nexts==k:
                    ready = True
                    steps[k] = len(resnow[-1])-1
                    break
            if ready:
                break
        resprev = resnow
    print(resprev[-1])
sums = 0
for k in steps:
    print(k,steps[k])
    sums += steps[k]
print(sums)
