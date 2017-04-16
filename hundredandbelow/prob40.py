# -*- coding: cp1252 -*-
import time

qaw = time.time()
i,jaakko = 1,''
while len(jaakko)<1000000:
	jaakko += str(i)
	i += 1
print int(jaakko[0])*int(jaakko[9])*int(jaakko[99])*int(jaakko[999])*int(jaakko[9999])*int(jaakko[99999])*int(jaakko[999999]),time.time()-qaw
