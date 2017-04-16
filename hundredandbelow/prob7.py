# -*- coding: cp1252 -*-

def isprime(laavaa):
	for kamal in range(2, int(laavaa**.5 + 1)):
		if laavaa%kamal == 0:
			return False
			laavaa = 0
			break
	if laavaa != 0:
		return True
jouno = []
qwerty = 2
while len(johno) < 10001:
	if isprime(qwerty):
		johno.append(qwerty)
	qwerty += 1
print johno[10000]
