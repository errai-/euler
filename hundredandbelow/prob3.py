# -*- coding: cp1252 -*-

def jakaja(jaa):
	baa = 1	
	raja = int(jaa**0.5) + 1
	for i in range(2, raja):
		if jaa%i == 0:
			jaa, baa = i, jaa/i
			break
	return jaa, baa
luvut = [600851475143]
i = 0
while i < len(luvut):
	a, b = jakaja(luvut[i])
	if b == 1:
		i = i + 1
	else:
		luvut.append(a)
		luvut.append(b)
		del luvut[i]
print luvut
