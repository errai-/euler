# -*- coding: cp1252 -*-
import time

t = time.time()
lue = open('cipher1.txt')
haa = lue.read()
lue.close()
i,nyaa = 0,[]
while i<len(haa)-1:
	if haa[i]==',':
		i+=1
	elif haa[i+1]==',':
		nyaa.append(int(haa[i]))
		i += 2
	elif haa[i+1]=='\n': i+=1
	else:
		nyaa.append(int(haa[i:i+2]))
		i+=2
sallitut = [33,39,40,41,59,44,48,49,50,51,52,53,54,55,56,57,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,81,82,83,84,85,86,87,88,89,90,32,46]

lamarr1,lamarr2,lamarr3 = [],[],[]
def thetruth(oo):
	lamarr = [0,0,'n']
	for a in range(97,123):
		i,count = oo,0
		cm = 'y'
		while i < len(nyaa):
			doo = nyaa[i]^a
			if doo in sallitut: count += 1
			else: cm = 'n'
			if lamarr[0]<count: lamarr[0]=count;lamarr[1]=a;lamarr[2]=cm
			i += 3
	return lamarr[1]
lamarr1,lamarr2,lamarr3 = thetruth(0),thetruth(1),thetruth(2)
stringi,i,suu = '',0,0
while i < len(nyaa):
	a = nyaa[i]^lamarr1
	stringi += chr(a); suu += a
	if i+1<len(nyaa):b = nyaa[i+1]^lamarr2; stringi += chr(b); suu += b
	if i+2<len(nyaa):c = nyaa[i+2]^lamarr3; stringi += chr(c); suu += c
	i += 3
print stringi,suu,time.time()-t,chr(lamarr1)+chr(lamarr2)+chr(lamarr3)
