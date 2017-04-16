# -*- coding: cp1252 -*-

import time

def osiin(lammas):
	s = 1
	q = 2
	while q <= int(lammas**0.5):
		if lammas%q == 0:
			lammas,s = lammas/q,q
			break
		q = q + 1
	suu = [lammas, s]
	return suu

def luvut(susi):
	luu = []
	luu.append(susi)
	osiin(luu[0])
	i = 0
	while i < len(luu):
		if osiin(luu[i])[1] != 1:
			luu = luu + osiin(luu[i])
			del luu[i]
		else:
			i = i + 1
	luu.sort()
	return luu

lisw = []
for su in range(1,21):
	for l in range(0,len(luvut(su))):
		for t in range(0, len(lisw)):
			if lisw[t] == luvut(su)[l]:
				del lisw[t]
				break
	lisw = lisw + luvut(su)
lisw.sort()
w = lisw[0]
for suukko in range(1, len(lisw)):
	w *= lisw[suukko]
print w
