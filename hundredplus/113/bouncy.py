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

def next(current):
    follow = []
    count = 0
    for pair in current:
        dir = pair[0]
        tot = pair[1]
        num = int(tot[-1])
        if dir == 0:
            count += 10
            follow.append([0,tot+str(num)])
            for i in range(num+1,10):
                follow.append([1,tot+str(i)])
            for i in range(0,num):
                follow.append([-1,tot+str(i)])
        elif dir<0:
            count += num+1
            for i in range(0,num+1):
                follow.append([-1,tot+str(i)])
        elif dir>0:
            count += 10-num
            for i in range(num,10):
                follow.append([1,tot+str(i)])
    return count,follow


def main():
    #nobounce = 99
    #for exponent in range(2,10):
    #    for i in range(1,10):
    #        nobounce += list(recurse(i,0,exponent))[0]
    #        print(i,exponent,nobounce)

    current = []
    nobounce = 99
    for i in range(1,10):
        for j in range(0,10):
            num = 10*i+j
            if i==j:
                current.append([0,str(num)])
            elif i>j:
                current.append([-1,str(num)])
            elif i<j:
                current.append([1,str(num)])
    print(current)

    for i in range(2,100):
        add,current = next(current)
        nobounce += add
        print(i,nobounce)

if __name__ == "__main__":
    main()
