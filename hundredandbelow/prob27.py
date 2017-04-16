# -*- coding: cp1252 -*-
import time

def giveprime(luku):
	haa = luku + 1
	while isprime(haa) != 1:
		haa += 1
	return haa
def isprime(luku):
	i,b = 2,1
	while i <= luku**0.5:
		if luku%i == 0: b=0;break
		i+=1
	return b
haa,checker = 1,[0]
while haa<1000:
	haa = giveprime(haa)
	huu = -1000
	oikeus = []
	while huu <= 1000:
		t=giveprime(haa)
		if (t-1-haa)<=1: huu+=1 ;continue
		if isprime(t-1-haa)==0: huu+=1; continue
		vali,tutkimus,jooei,n = [],haa+1,1,2
		print "-",haa,huu
		while jooei:
			vali.append(tutkimus)
			tutkimus = n**2 + huu*n + haa
			if tutkimus <= 1: break
			jooei = isprime(tutkimus)
			print tutkimus
			if len(vali)>len(oikeus): oikeus,a,b = vali,huu,haa
			n += 1
		huu += 1
	if checker[0]<len(oikeus): checker,muut=[len(oikeus),a,b],oikeus
print checker,checker[1]*checker[2],muut
