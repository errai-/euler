from primefacs import *

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
    result = 0
    number = 4
    while result<1000:
        result = Handler(number).recurse(1,0)
        number += 1
    print number,result

if __name__ == "__main__":
    main()
