from os import system
import random
from random import shuffle
Z = 3
print Z
for z in range(0,Z):
	n=random.randint(1,10)
	print n
	T=[]
	for i in range(1,n+1):
		T.append(i)
	shuffle(T)	
	for i in range(0,n):
		print T[i],
	k=random.randint(1,100)
	print "\n",k
	for i in range(0,k):
		a,b = random.randint(1,n) , random.randint(1,n)
		if(a>b):a,b = b, a
		print a,b
