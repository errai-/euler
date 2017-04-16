# -*- coding: cp1252 -*-
import time
huu = time.time()
sumo = 0
for i in range (1,1001):sumo += i**i
print (str(sumo))[len(str(sumo))-10:len(str(sumo))+1],time.time()-huu
