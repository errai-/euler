import itertools

primes = [2,3,5,7,11,13]

def isprime(num):
    if all(num%i!=0 for i in primes[:primes.index(next(x for x in primes if x>num**0.5))]):
        return True
    else:
        return False

for num in range(15,31500,2):
    if isprime(num):
        primes = primes + [num]

def generate_groupings(xs):
    for bits in range(2 ** (len(xs)-1)):  # int representing n-1 bits
        grouping = [xs[0]]             # grouping starts with first item
        allgood = True
        for x in xs[1:]:                  # for each remaining item...
            bits, b = divmod(bits, 2)     # pop one bit off of the list
            if b:                         # case 1: no separation
                grouping = grouping[:-1] + [grouping[-1] + x]
            else:                         # case 0: separation
                if not isprime(int(grouping[-1])):
                    allgood = False
                    break
                grouping += [x]
        if not allgood or not isprime(int(grouping[-1])):
            continue
        yield grouping

permcount = 0
allperms = 362880
for row in itertools.permutations('123456789'):
    permcount += 1
    results = list(generate_groupings(row))
    if results != []:
        print(permcount,allperms,results)
