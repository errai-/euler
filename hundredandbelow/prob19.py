# -*- coding: cp1252 -*-

count = 100*365+(100/4)*1

pv = 365%7

def vuosi(v,pav):
	s = 0
	tam = maa = tou = hei = elo = lok = jou = 31%4
	if v%4 == 0: hel = 29%4
	else: hel = 28%4
	huh = kes = syy = mar = 30%4
	kuuk = [tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mar, jou]
	for i in kuuk:
		pav = (pav + i)% 7
		if pav == 6: s += 1
	return pav,s
kok = 0
for i in range(1901,2001):
	pv,k = vuosi(i,pv)
	kok += k
	k = 0
print kok, pv
