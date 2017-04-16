# -*- coding: cp1252 -*-
import time
kellari = time.time()
def potenssit(aapinen):
	suho = 0
	for i in aapinen:
		suho += int(i)**5
	if int(aapinen) == suho: return suho
	else: return 0
suu = 0
for i in range(2,1000000):
	suu += potenssit(str(i))
	print suu
print suu, time.time()-kellari #aikaa otettu varman päälle liikaa, nytkin suorittuu neljännesminuutissa
