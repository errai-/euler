


# Minimum divisor = 11
for divisor in range(1000001,2000000,2):
    if divisor%5==0:
        continue
    rkmod = 1
    levels = 1
    prev = 1
    while rkmod!=0:
        levels += 1
        prev *= 10
        prev = prev%divisor
        rkmod += prev
        rkmod = rkmod%divisor
    print(divisor,levels)
    if levels>=1000000:
        break


