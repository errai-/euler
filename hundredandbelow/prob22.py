# -*- coding: cp1252 -*-

def arvot(kirjain):
	dicas = {'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,'I':9,'J':10,'K':11,'L':12,'M':13,'N':14,'O':15,'P':16,'Q':17,'R':18,'S':19,'T':20,'U':21,'V':22,'W':23,'X':24,'Y':25,'Z':26}
	return dicas[kirjain]	
amenhotep = open('./names.txt')

kahva = amenhotep.readline()
amenhotep.close()
maa = ''
x = 1
while kahva[x] != '"':
	maa += kahva[x]
	x += 1
kahvia = [maa]
teeta = []
x = 0#tyritty tässä
while x < len(kahva):
	if kahva[x] == ',':
		a = ''
		x += 2
		while kahva[x] != '"':
			a += kahva[x]
			x += 1
		kahvia.append(a)
	x += 1
kahvia.sort(key = str.lower)
for shalaakso in range (0,len(kahvia)):
	q = 0
	rasa = list(kahvia[shalaakso])
	for menija in rasa:
		q += arvot(menija)
	teeta.append(q*(shalaakso+1))
s = 0
for muu in teeta:
	s += muu
print kahvia,s
