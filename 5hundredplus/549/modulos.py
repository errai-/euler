from collections import defaultdict

primes = []
def isprime(num):
    if num==1:
        return False
    elif all(num%i!=0 for i in primes[:primes.index(next(x for x in primes if x>num**0.5))]):
        return True
    else:
        return False

with open('../../primes_to25M.txt','r') as f:
    primes = list(map(lambda l : int(l.strip('\n')),f.readlines()))

def divisors(num):
    idx = 0
    results = defaultdict(int)
    while primes[idx]<=num**0.5:
        while num%primes[idx]==0:
            results[primes[idx]] += 1
            num = num/primes[idx]
        idx += 1
    if num>1:
        results[num] = 1
    return results

facts = defaultdict(int)
def minimal(no,reps):
    curreps = 0
    name = str(no)+"-"+str(reps)
    if name in facts:
        return facts[name]
    else:
        for nn in range(no,(reps+1)*no,no):
            tmpnn = nn
            while tmpnn%no==0:
                tmpnn = tmpnn/no
                curreps += 1
                if curreps>=reps:
                    facts[name] = nn
                    return nn
    facts[name] = reps*no
    return reps*no

def sfunc(num):
    divs = divisors(num)
    currmax = 0
    for div in divs:
        curr = minimal(div,divs[div])
        if curr>currmax:
            currmax = curr
    return currmax

cumulator = 0
for nro in range(2,100000001):
    if nro%100000==0: print(nro)
    cumulator += sfunc(nro)
print(cumulator)
