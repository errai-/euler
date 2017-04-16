# -*- coding: cp1252 -*-
import time

alfa = time.time()
kolmio = []
kahvia = open('triangle.txt')
for a in kahvia.readlines():
	vaasa,iimi = [],0
	while iimi < len(a):
		if a[iimi]==' ' or a[iimi]=='\n':
			iimi+=1
		else:
			vaasa.append(int(a[iimi:iimi+2]))
			iimi += 3
	kolmio.append(vaasa)
kahvia.close()
mustafa = len(kolmio)
for rastafari in range(mustafa-1):
	hoo = kolmio[mustafa-1-rastafari]
	for hermanos in range(len(hoo)-1):
		if hoo[hermanos]>hoo[hermanos+1]:
			kolmio[mustafa-2-rastafari][hermanos]+=hoo[hermanos]
		else:
			kolmio[mustafa-2-rastafari][hermanos]+=hoo[hermanos+1]
print kolmio[0][0],time.time()-alfa
