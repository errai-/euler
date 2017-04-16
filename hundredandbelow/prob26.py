# -*- coding: cp1252 -*-
import time

elnino = time.time()
def kavio(l):
	if l%2==0:return 1
	elif l%5==0: return 1
	else: return 0
def koeksistentti(uu,p=1):
	while 1:
		saturn = (10**(2*p))/uu
		if saturn < 100: p+=1; continue
		if (int(len(str(saturn))/2)*2)!=len(str(saturn)): saturn = 10*(10**(2*p))/uu
		io = str(saturn)
		if saturn==0: p += 1; continue
		if io[:len(io)/2]==io[len(io)/2:len(io)]: kuha = io[:len(io)/2]; break
		p += 1
	return kuha
def viili(uuu,p=1):
	while 1:
		saturn = (10**(2*p))/uuu
		if (int(len(str(saturn))/2)*2)!=len(str(saturn)): saturn = 10*(10**(2*p))/uuu
		io = str(saturn)
		if saturn==0: p += 1; continue
		if io[:len(io)/2]==io[len(io)/2:len(io)]: kuha = io[:len(io)/2]; break
		p += 1
	if int(kuha)<100:
		c = koeksistentti(uuu)
		q = str((10**(2*len(kuha)))*(int(kuha))+(10**(len(kuha)))*(int(kuha))+int(kuha))
		print c[0:len(q)],q,c
		if q!=c[0:len(q)]: kuha = c
		if len(c)>6: kuha=c
	return kuha
kaa = 0
for i in range(3,1001):
	if kavio(i) == 1: continue
	print i
	c=viili(i)
	print kaa
	if len(str(c))>len(str(kaa)): kaa=c;rastafari=i
print kaa,rastafari, time.time() - elnino # paljon optimoitavaa, huomataan, että olisi jo vähitellen aika oppia uutta
