# -*- coding: cp1252 -*-


def laskin(k):
	a = 0
	i = 1
	while i*k < 1000:
		a = a + i*k
		i = i + 1
	return a
print laskin(3) + laskin(5) - laskin(15)
