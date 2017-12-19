from collections import OrderedDict
from operator import itemgetter

primes = [2,3,5,7,11,13]
uplim = 1000000


def isprime(num):
    if num==1:
        return False
    elif all(num%i!=0 for i in primes[:primes.index(next(x for x in primes if x>num**0.5))]):
        return True
    else:
        return False

for num in range(15,int(uplim**0.5+1),2):
    if isprime(num):
        primes = primes + [num]

# I cannot understand what the value besides 2 is, but this really does not matter
tiles = [0,2]
for layer in range(2,(uplim-5)/12):
    n6 = layer*6
    if isprime(n6-1):
        n12 = 2*n6
        if isprime(n6+1) and isprime(n12+5):
            tiles.append(2+3*layer*(layer-1))
        if isprime(n6+5) and isprime(n12-7):
            tiles.append(1+3*layer*(layer+1))
        if len(tiles)>=2000:
            break
print(tiles[1999],len(tiles))

