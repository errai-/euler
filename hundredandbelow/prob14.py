# -*- coding: cp1252 -*-
# kakkaa
# listaa turhaan saadut numerot, eikä edes yritä optimoida
import time
def seuraava(l):
	if l%2 == 0:
		l = l/2
	else: l = 3*l + 1
	if l == 1:
		return 'stop'
	else: return l
ahaa = time.time()
win = [0,0]
s = 2
kaikki = []
for i in range(500001,1000001,2):
	if kaikki.count(i) == 1: continue
	s = i
	vali = [i]
	valimerkki = 1
	while seuraava(s) != 'stop':
		s = seuraava(s)
		if kaikki.count(s) == 1:
			if valimerkki == 1:
				kaikki = kaikki + vali
				valimerkki = 2
		vali.append(s)
	if valimerkki == 1: kaikki = kaikki + vali
	if len(vali) > win[0]:
		del win
		win = []
		win.append(len(vali))
		win.append(vali[0])
print win
print time.time()-ahaa
