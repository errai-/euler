from primes import *

class Handler:
    def __init__(self,numlen):
        self.prim = primes(316228)
        self.len = numlen

    def inspector(self,num):

        for intruders in range(1,self.len):
            val = self.iterator(num,"",intruders)
            if val>0:
                return intruders,val

    def iterator(self,num,curr,ileft):

        if curr=="0":
            return 0
        if len(curr)==self.len:
            if (self.prim.isprime(int(curr))):
                return int(curr)
            else:
                return 0

        count = 0
        if self.len>len(curr)+ileft:
            count += self.iterator(num,curr+str(num),ileft)
        if ileft>0:
            for i in range(0,10):
                count += self.iterator(num,curr+str(i),ileft-1)

        return count

def main():
    suu = Handler(10)
    summer = 0
    for i in range(0,10):
        hold = suu.inspector(i)
        print hold
        summer += hold[1]
    print summer

if __name__ == "__main__":
    main()
