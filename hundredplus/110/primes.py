from math import floor

def division(n,divider):
    count = 0
    while (n%divider==0):
        n/=divider
        count+=1
    return [n,count]

def primefacs(n):
    facs = []
    if n<2:
        return facs

    [n,count]=division(n,2)
    if count>0:
        facs.append([2,count])
    limit = floor(n**0.5)
    div=3
    while div<=limit:
        [n,count]=division(n,div)
        if count>0:
            facs.append([div,count])
            limit = floor(n**0.5)
        div += 2
    if n>1:
        facs.append([n,1])
    return facs

class primes:
    def __init__(self,n):
        self.n = n
        self.primes = [2]
        self.fill()

    def isprime(self,number):
        limit = floor(number**0.5)
        purity = True
        for prim in self.primes:
            if prim>limit:
                break
            if number%prim==0:
                purity = False
                break
        return purity


    def fill(self):
        num = 3
        while num<=self.n:
            if self.isprime(num):
                self.primes.append(num)
            num += 2
