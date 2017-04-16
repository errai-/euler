# -*- coding: cp1252 -*-
import time
aika = time.time()
numeros = []
for i in range(1,21):
	numeros.append(0.5*(i**2+i))
def hermanosnumeros(nimi):
	vastaavuudet = {'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,'I':9,'J':10,'K':11,'L':12,'M':13,'N':14,'O':15,'P':16,'Q':17,'R':18,'S':19,'T':20,'U':21,'V':22,'W':23,'X':24,'Y':25,'Z':26}
	suma = 0
	for juoksija in nimi:
		suma += vastaavuudet[juoksija]
	k,ish = 0,float((-1 + (1 + 8*suma)**0.5)/2)
	if suma in numeros:
		k = 1
	return k
kahva = open('words.txt')
jawohl = kahva.read()
kahva.close()
i,nimet = 1,[]
while i < len(jawohl):
	if jawohl[i] == '"':
		i += 3
	else:
		o = i
		while jawohl[o]!='"':
			o += 1
		nimet.append(jawohl[i:o])
		i = o
tulos = 0
for aamos in nimet:
	tulos += hermanosnumeros(aamos)
print tulos,time.time()-aika
