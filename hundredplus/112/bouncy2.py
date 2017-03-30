from primes import *

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

# Give the number in a string format
def bounciness(num):
    dir = 0
    prev = num[0]
    redundance = prev
    for i in range(1,len(num)):
        if dir==0:
            if num[i]>prev:
                dir=1
            elif num[i]<prev:
                dir=-1
        elif dir<0:
            if num[i]>prev:
                redundance += "9"
                for i in range(i+1,len(num)):
                    redundance += "9"
                return int(redundance)
        elif dir>0:
            if num[i]<prev:
                redundance += str(int(prev)-1)
                for i in range(i+1,len(num)):
                    redundance += "9"
                return int(redundance)
        prev = num[i]
        redundance += prev
    return -1

def absolute(num):
    dir = 0
    prev = num[0]
    for i in range(1,len(num)):
        if dir==0:
            if num[i]>prev:
                dir=1
            elif num[i]<prev:
                dir=-1
        elif dir<0 and num[i]>prev:
            return 1
        elif dir>0 and  num[i]<prev:
            return 1
        prev = num[i]
    return -1

def main():
    nobounce = 99
    bounce = 0.0
    b = 0
    for i in range(100,10000000):
        ratio = bounce/(bounce+nobounce)
        if ratio==0.99:
            print(i-1,ratio)
        if i <= b:
            bounce += 1
            continue
        b = bounciness(str(i))
        if b < 0:
            nobounce += 1
        else:
            bounce += 1
    nobounce = 100
    bounce = 0.0
    for i in range(1,10):
        nxt = list(recurse(i,0,5))
        nobounce += nxt[0]
        bounce += nxt[1]
        print(i,bounce/(bounce+nobounce))


if __name__ == "__main__":
    main()
