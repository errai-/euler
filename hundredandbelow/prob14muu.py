# -*- coding: cp1252 -*-
# 59.9775159359 :O jos numeroita ei listata, saatavissa parempi tulos?
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
for i in range(500004,1000001,6):
	if kaikki.count(i) == 1: continue
	s = i
	vali = [i]
	valimerkki = 1
	while seuraava(s) != 'stop':
		s = seuraava(s)
		vali.append(s)
	if len(vali) > win[0]:
		del win
		win = []
		win.append(len(vali))
		win.append(vali[0])
	for hahaa in range(len(vali)):
		if vali[hahaa] != 1:
			del vali[hahaa:]
			break
	kaikki.extend(vali)
	kaikki.sort()
for i in range(500001,1000001,2):
	if kaikki.count(i) == 1: continue
	s = i
	vali = [i]
	valimerkki = 1
	while seuraava(s) != 'stop':
		s = seuraava(s)
		vali.append(s)
	if len(vali) > win[0]:
		del win
		win = []
		win.append(len(vali))
		win.append(vali[0])
	for hahaa in range(len(vali)):
		if vali[hahaa] != 1:
			del vali[hahaa:]
			break
	kaikki.extend(vali)
	kaikki.sort()
print win
print time.time()-ahaa
