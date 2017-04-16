# -*- coding: cp1252 -*-



marrakesh = """sdfgasdf\n
dghdfgdgfdfg
asdfasd
paa\n"""

marrakesh = str(marrakesh)

for i in range(0, len(marrakesh)-1):
	if marrakesh[i:i+1] == '''
''':
		marrakesh = marrakesh[:i]+marrakesh[i+1:]

def isprime(laavaa):
	for kamal in range(2, int(laavaa**.5 + 1)):
		if laavaa%kamal == 0:
			return False
			laavaa = 0
			break
	if laavaa != 0:
		return True

print isprime(13)
