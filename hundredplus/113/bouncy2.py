
def factorial(n):
    if n>2:
        return n*factorial(n-1)
    return n

def paths(numlen):
    curr = 1
    num = 9*curr
    curr *= numlen+1
    num += 17*curr
    curr *= (numlen+2)/2
    num += 15*curr
    curr *= (numlen+3)/3
    num += 13*curr
    curr *= (numlen+4)/4
    num += 11*curr
    curr *= (numlen+5)/5
    num += 9*curr
    curr *= (numlen+6)/6
    num += 7*curr
    curr *= (numlen+7)/7
    num += 5*curr
    curr *= (numlen+8)/8
    num += 3*curr
    curr *= (numlen+9)/9
    num += curr
    return num

def main():
    nobounce = 99

    for i in range(2,100):
        nobounce += paths(i-1)
        print(i,nobounce)

if __name__ == "__main__":
    main()
