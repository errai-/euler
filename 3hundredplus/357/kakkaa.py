from collections import OrderedDict
from operator import itemgetter
import sys

#uplim = 1000
uplim = 100000000

# Warning: does not handle 1 or uneven numbers
def primefacs(num,primes):
    primeidx = 0
    results = dict()
    while num!=1 and primeidx<len(primes):
        cprime = primes[primeidx]
        primeidx += 1
        if num%cprime==0:
            results[cprime] = 1
            num /= cprime
            if num%cprime==0:
                return dict()
    if num>1:
        results[num] = 1
    return results

# Should not be given the value of 1 or 2
def divisors(num,primes):
    pf = primefacs(num,primes)
    if len(pf)==0:
        return []
    limit = int(num**0.5)
    prevcases = [1]
    for div in pf:
        currcases = list(prevcases)
        nu = 1
        for i in range(0,pf[div]):
            nu *= div
            if nu>limit:
                break
            for pc in prevcases:
                tmp = pc*nu
                if tmp>limit:
                    continue
                currcases.append(tmp)
        prevcases = currcases
    prevcases.remove(1)
    prevcases.remove(2)
    return prevcases

def isprime(num,primes):
    if num==1:
        return False
    elif all(num%i!=0 for i in primes[:primes.index(next(x for x in primes if x>num**0.5))]):
        return True
    else:
        return False

with open("../../primes_to100M.txt",'r') as f:
    primes = [x for x in map(int,map(lambda s : s.strip('\n'),f.readlines())) if x<uplim/2+2]
    sumnums = 3 # take 1 and 2 into account
    for p2 in primes[2:]:
        num = 2*p2-4
        if not isprime(num+1,primes):
            continue
        OK = True
        lim = int(num**0.5)
        for i in range(3,lim+1):
            if num%i==0:
                if not isprime(num/i+i,primes):
                    OK = False
                    break
        if OK:
            print(num)
            sumnums+=num
    print(sumnums)
