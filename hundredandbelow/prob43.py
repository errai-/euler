# -*- coding: cp1252 -*-
import time

digits,koo = [1,2,3,4,5,6,7,8,9,0],time.time()

def tarkistus(daavid):
	if int(daavid[1:4])%2 == 0:
		if int(daavid[2:5])%3 == 0:
			if int(daavid[3:6])%5 == 0:
				if int(daavid[4:7])%7 == 0:
					if int(daavid[5:8])%11 == 0:
						if int(daavid[6:9])%13 == 0:
							if int(daavid[7:10])%17 == 0: 
								q = int(daavid)
							else: q = 0
						else: q = 0
					else: q = 0
				else: q = 0
			else: q = 0
		else: q = 0
	else: q = 0
	return q

def permutations(listb,listd):
	if listd == []:
		daavid = ''
		for a in listb:
			daavid += str(a)
		daavid = tarkistus(daavid)
	else:	
		daavid = 0	
		for a in range(len(listd)):
			listc,lista = [],[]
			listc.extend(listd)
			lista.extend(listb)
			lista.append(listc.pop(a))
			if lista[0] != 0:
				daavid += permutations(lista,listc)
			else: continue
	return daavid
print permutations([],digits)
print time.time() - koo
