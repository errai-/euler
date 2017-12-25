primes = [2,3,5,7,11,13]
uplim = 100000

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

numlist = []
sump = 0
for p in primes:
    rs = []
    tens = []
    now = 1
    tnow = 10%p
    for i in range(0,100): # This turned out to be uneventful - we find the zero sequence easily
    #while now not in rs:
        rs.append(now)
        tens.append(tnow)
        for j in range(0,9):
            now = (((now*tens[-1])%p)+rs[-1])%p
            tnow = (tnow*tens[-1])%p

    if 0 in rs:
        print(p,rs.index(0))
    else:
        sump += p
print(sump)
