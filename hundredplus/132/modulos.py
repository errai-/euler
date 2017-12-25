primes = [2,3,5,7,11,13]
uplim = 200000

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
for p in primes:
    rs = [1]
    tens = [10%p]
    for i in range(0,29):
        rs.append(rs[-1]*(tens[-1] + 1) % p)
        tens.append((tens[-1]*tens[-1]) % p)
    cumul = rs[29]                                # 2^29
    cumul = (((cumul*tens[28]) % p) + rs[28]) % p # 2^28
    cumul = (((cumul*tens[27]) % p) + rs[27]) % p # 2^27
    cumul = (((cumul*tens[25]) % p) + rs[25]) % p # 2^25
    cumul = (((cumul*tens[24]) % p) + rs[24]) % p # 2^24
    cumul = (((cumul*tens[23]) % p) + rs[23]) % p # 2^23
    cumul = (((cumul*tens[20]) % p) + rs[20]) % p # 2^20
    cumul = (((cumul*tens[19]) % p) + rs[19]) % p # 2^19
    cumul = (((cumul*tens[17]) % p) + rs[17]) % p # 2^17
    cumul = (((cumul*tens[15]) % p) + rs[15]) % p # 2^15
    cumul = (((cumul*tens[14]) % p) + rs[14]) % p # 2^14
    cumul = (((cumul*tens[11]) % p) + rs[11]) % p # 2^11
    cumul = (((cumul*tens[9]) % p) + rs[9]) % p   # 2^9

    if cumul==0:
        numlist.append(p)
        if (len(numlist)==40):
            print(p)
            break
print(len(numlist),sum(numlist))
