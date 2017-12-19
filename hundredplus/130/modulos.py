primes = [2,3,5,7,11,13]
uplim = 20000

def isprime(num):
    if num==1:
        return False
    elif all(num%i!=0 for i in primes[:primes.index(next(x for x in primes if x>num**0.5))]):
        return True
    else:
        return False

for num in range(15,2*int(uplim**0.5),2):
    if isprime(num):
        primes = primes + [num]

numlist = []
# Minimum divisor = 11
for divisor in range(11,uplim-2,2):
    if divisor%5==0:
        continue
    if isprime(divisor):
        continue

    rkmod = 1
    levels = 1
    prev = 1
    while rkmod!=0:
        levels += 1
        prev *= 10
        prev = prev%divisor
        rkmod += prev
        rkmod = rkmod%divisor
    if (divisor-1)%levels==0:
        numlist.append(divisor)
        if len(numlist)==25:
            break
print(len(numlist),sum(numlist))


