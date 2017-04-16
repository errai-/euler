# -*- coding: cp1252 -*-
import time
from numpy import matrix
from numpy import linalg

juoksija,summ = 1,1
for c in range(1,501):
	muut = 2*c
	for i in range(4):
		juoksija += muut
		summ += juoksija
print summ
	

