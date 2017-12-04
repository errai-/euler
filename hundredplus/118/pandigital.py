import itertools
import math

# better solution would be just to loop over fitting primes. The current takes 3 min

primes = [2,3,5,7,11,13]

def isprime(num):
    if num==1:
        return False
    elif all(num%i!=0 for i in primes[:primes.index(next(x for x in primes if x>num**0.5))]):
        return True
    else:
        return False

def primeperm(strnum):
    return any(isprime(x) for x in [int(''.join(x)) for x in itertools.permutations(strnum)])

for num in range(15,31500,2):
    if isprime(num):
        primes = primes + [num]

possibilities = []
def generate_groupings(current,joining,jplace,xs):
    if xs=='':
        possibilities.append(current)
    elif joining:
        for i in range(jplace,len(xs)):
            news = current[:-1] + [current[-1]+xs[i]]
            olds = xs[:i]+xs[i+1:]
            if i+1<len(xs):
                generate_groupings(news,True,i,olds)
            if primeperm(news[-1]):
                generate_groupings(news,False,i,olds)
    else:
        current = current+[xs[0]]
        if len(xs)>1:
            generate_groupings(current,True,0,xs[1:])
        if primeperm(current[-1]):
            generate_groupings(current,False,0,xs[1:])

generate_groupings([],False,0,'123456789')
print(possibilities)
allposs = 0
for group in possibilities:
    multiplier = 1
    for num in group:
        multiplier *= sum([isprime(x) for x in [int(''.join(x)) for x in itertools.permutations(num)]])
    allposs += multiplier

print(len(possibilities),allposs)
