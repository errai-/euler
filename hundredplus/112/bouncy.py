from primes import *

def test():
    return 1,2

def recurse(previous,dir,left):
    if left==0:
        return [1,0]

    count = [0,0]
    if dir==0:
        count = map(sum,zip(count,recurse(previous,0,left-1)))
        for i in range(0,previous):
            count = map(sum,zip(count,recurse(i,-1,left-1)))
        for i in range(previous+1,10):
            count = map(sum,zip(count,recurse(i,1,left-1)))
    elif dir<0:
        count[1] += (9-previous)*10**(left-1)
        for i in range(0,previous+1):
            count = map(sum,zip(count,recurse(i,-1,left-1)))
    elif dir>0:
        count[1] += previous*10**(left-1)
        for i in range(previous,10):
            count = map(sum,zip(count,recurse(i,1,left-1)))
    return count            

def partials(num,dir):
    strnum = str(num)
    count = [0,0]
    if dir==0:
        if len(num)==1:
            return [1,0]
        begin = int(strnum[0])
        next = int(strnum[1])
        if next>begin:
            dir=1
        elif next<begin:
            dir=-1
        for i in range(0,min(begin,next)):
            count = map(sum,zip(count,recurse(i,-1,len(num)-2)))
        if begin<next:
            count = map(sum,zip(count,recurse(begin,0,len(num)-2)))
        for i in range(begin+1,next):
            count = map(sum,zip(count,recurse(i,1,len(num)-2)))
        count = map(sum,zip(count,partials(num[1:],dir)))
    elif dir>0:
        
    elif dir<0:
        

def main():

    nobounce = 100
    bounce = 0.0
    for i in range(2,6):
        nxt = recurse(i,0,2)
        nobounce += nxt[0]
        bounce += nxt[1]
        print i, bounce/(nobounce+bounce)

if __name__ == "__main__":
    main()
