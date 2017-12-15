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

for num in range(15,100000,2):
    if isprime(num):
        primes = primes + [num]

# Warning: does not handle 1 or uneven numbers
def primefacs(num):
    primeidx = 0
    result = 1
    while num!=1 and primeidx<len(primes):
        cprime = primes[primeidx]
        primeidx += 1
        if num%cprime==0:
            result *= cprime
            while num%cprime==0:
                num /= cprime
    return result

results = dict()
for i in range(1,100001):
    results[i] = primefacs(i)

ros = OrderedDict(sorted(results.items(), key=lambda t: t[1]))
print(ros.keys()[10000-1])
