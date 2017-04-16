# -*- coding: cp1252 -*-




def sisalla(kaato,hirvi,laba = [],kuu=0):
	kok = []
	print kaato, hirvi	
	for i in range(len(kaato)):
		sana = kaato.pop(i)
		if kuu == 0:
			for i in range(len(kaato)):
				laba.append([sana])
			print laba
		elif kuu == 1:
			for i in range(len(laba)):
				laba[i].append(sana)
			print laba
		if hirvi > 1:
			laba = sisalla(kaato,hirvi-1,laba,1)
		if kuu == 0:
			kok.extend(laba)
			laba = []
	if kuu == 1: return laba
	if kuu == 0: return kok
print [22,44],'F.U.C.K. on his windshield'
print sisalla([3,5,7],2)
