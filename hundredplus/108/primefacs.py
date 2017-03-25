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
