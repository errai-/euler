# -*- coding: cp1252 -*-

def kolmiojakaja(maksa):
	for i in range(100, 999):
		if maksa%i == 0:
			if 99 < maksa/i < 1000:
				maksa = i
				break
	return maksa
maksa = a = 999801
while maksa == a:
	maksa = a = a - 1
	if str(a) == str(a)[::-1]:
		maksa = kolmiojakaja(a)
print maksa, a/maksa, a

