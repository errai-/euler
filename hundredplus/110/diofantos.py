from primes import *

# An ugly solution but it works.
# Only use numbers with lots of "early" prime factors
# Best will be [2^3,3^3,5^2,7^2,11,13,19,23,29,31,39,41]

def nsquarefacs(n):
    facs = primefacs(n)
    newfacs = []
    for i, fac in enumerate(facs):
        newfacs.append([fac[0],2*fac[1]])
    return newfacs

class Handler:
    def __init__(self,n):
        self.facs = nsquarefacs(n)
        self.n = n

    def recurse(self, current, position):
        if position>=len(self.facs):
            return 1
        else:
            fac = self.facs[position]
            position += 1
            cumulator = 0
            for i in range(0,fac[1]+1):
                if current>self.n:
                    break
                cumulator += self.recurse(current,position)
                current *= fac[0]
            return cumulator


def main():
    prim = primes(1000)
    n1 = 1
    results = []
    for l1 in range(0,14):
        n2 = n1
        for l2 in range(0,l1-1):
            print l1,l2
            n3 = n2
            for l3 in range(0,l2-1):
                if n3 > 34283810182822200:
                    break
                res = Handler(n3).recurse(1,0)
                if res >= 4000000:
                    results.append([n3,res,l1,l2,l3])
                n3 *= prim.primes[l3]
            n2 *= prim.primes[l2]
        n1 *= prim.primes[l1]
    print results

if __name__ == "__main__":
    main()
