import math

def ispalindrome(num):
    strnum = str(num)
    half = int(math.ceil(len(strnum)/2.0))
    return strnum[:half]==strnum[::-1][:half]

limit = 10**8
def largestnum(N):
    return int((-N+1+((N-1)**2+(4.0/N)*(limit-sum(i**2 for i in range(1,N))))**0.5)/2.0)

maxima = dict()
totmax = 0
for i in range(2,1001):
    num = largestnum(i)
    if num<1:
        break
    maxima[i] = num
    if num>totmax:
        totmax=num

visited = []
sumnums = 0
for i in range(1,totmax+1):
    N = 2
    squares = i**2
    while N in maxima and maxima[N]>=i:
        squares += (i+N-1)**2
        if squares>limit:
            break
        if ispalindrome(squares):
            print(i,N,squares)
            if squares not in visited:
                sumnums += squares
                visited.append(squares)
        N += 1
print(sumnums)
