# -*- coding: cp1252 -*-
import time
import fractions

def nexus(num,loo = [],laskin=1):
	if loo == []:
		ohoo = int(num**0.5)
		os,nim,gospel = 1,num**2-ohoo**2,1
		while ohoo - gospel*nim >= 0:
			gospel += 1
		print os,nim,ohoo,num,gospel
		ohoo -= gospel*nim
		ohoo *= -1
		loo.append([ohoo,os,nim,gospel])
		print loo
		doo = nexus(num,loo,laskin+1)	
	else:
		rho,os,nimv = loo[len(loo)-1][0],loo[len(loo)-1][2],loo[len(loo)-1][1]
		nim = num**2-rho**2
		nim*=nimv
		a = fractions.gcd(os,nim)
		os /= a
		nim /= a
		if nim == 1:
			gospel,ohoo = rho + int(num),int(num)
		else:
			gospel = 1
			while rho - gospel*nim >= 0:
				gospel += 1
			ohoo = gospel*nim - rho
			gospel *= os
		daavid = [ohoo,os,nim,gospel]
		print loo
		if loo[0] == daavid: doo = laskin
		else: 
			loo.pop(len(loo)-1)
			loo.append(daavid)
			doo = nexus(num,loo,laskin+1)
	return doo

print nexus(23)


