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

for num in range(15,300000,2):
    if isprime(num):
        primes = primes + [num]

for i in range(0,len(primes),2):
    prim = primes[i]
    val = 2*(i+1)*prim
    if val>10**10:
        print(i+1)
        break

print(len(primes))
