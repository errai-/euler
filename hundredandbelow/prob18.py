# -*- coding: cp1252 -*-
import time
# luotiin koodi, jolla luonnos paljastuu
woot = time.time()
dasp = []
dime = '''75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23'''
i,vali = 0,[]
while i<len(dime):
	if dime[i]!=' ' and dime[i]!='\n':
		vali.append(int(dime[i:i+2]))
		i += 2
	elif dime[i]==' ': i+=1
	else:
		dasp.append(vali)
		vali = []
		i+=1
	if i>= len(dime): dasp.append(vali)
dasp.append([0]*(len(dasp)+1))
dasp.append([0]*(len(dasp)+1))

def next3(juuri,rivi):
	sumos = 0
	doop = []
	doop.append(dasp[rivi][juuri-1:juuri+1])
	doop.append(dasp[rivi+1][juuri-1:juuri+2])
	if doop[1][0]>doop[1][1]:
		doop[0][0]+=doop[1][0]
	else: doop[0][0]+=doop[1][1]
	if doop[1][1]>doop[1][2]:
		doop[0][1]+=doop[1][1]
	else: doop[0][1]+=doop[1][2]
	if doop[0][0]>doop[0][1]:
		aa = 0
	else: aa = 1
	return aa
paikka,suu = 1,dasp[0][0]
for rivi in range(1,len(dasp)-2):
	paikka += next3(paikka,rivi)
	suu += dasp[rivi][paikka-1]
print suu,time.time()-woot
