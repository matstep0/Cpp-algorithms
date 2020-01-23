from os import system
import time
i = 1
while 1:
	system("time ./moj < test"+str(i)+".in > moj.out")
	time.sleep(2)
	if system("diff -q moj.out test"+str(i)+".out"):
		break
	else:
		print "OK",i
	i = i + 1
