import math

def testing(num):
    strnum = str(num)
    if strnum[-1]!='0' or strnum[-3]!='9' or strnum[-5]!='8' or strnum[-7]!='7':
        return False
    elif strnum[-9]!='6' or strnum[-11]!='5' or strnum[-13]!='4':
        return False
    elif strnum[-15]!='3' or strnum[-17]!='2' or strnum[-19]!='1':
        return False
    else:
        return True

smallest = 1020304050607080900
biggest = 1929394959697989990
for i in range(int(smallest**0.5),int(biggest**0.5)+1):
    square = i**2
    if testing(square):
        print(i,square)
