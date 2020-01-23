from os import system
import time
i = 1
while 1:
	system("./gen >test.in")
	system(" ./F1_przeplyw < test.in > moj.out")
	system("./f1<test.in> test.wzo")
	if system("diff -q moj.out test.wzo"):
		break
	else:
		print "OK",i
	i = i + 1
