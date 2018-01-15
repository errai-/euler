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

stronk = []
currents = range(1,10)
currsum = range(1,10)
currdivs = [False,False,False,False,False,False,False,False,False]
for round in range(13):
    prevs = currents
    prevsum = currsum
    prevdivs = currdivs
    currents = []
    currsum = []
    currdivs = []
    print(round)
    for pi in range(len(prevs)):
        prev = 10*prevs[pi]
        psum = prevsum[pi]
        for add in range(10):
            tmp = prev + add
            tmpsum = psum+add
            if tmp%tmpsum==0:
                currents += [tmp]
                currsum += [tmpsum]
                currdivs += [isprime(tmp/tmpsum)]
            if prevdivs[pi]:
                if isprime(tmp):
                    stronk.append(tmp)
                    print(tmp,prevs[pi]/prevsum[pi],isprime(prevs[pi]/prevsum[pi]))

print(sum(stronk))
