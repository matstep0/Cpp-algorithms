from os import system	
i=1
while i:
	system("python gen.py>test.in")
	system("./main <test.in>test.wzo")
	system("./wzozio <test.in>test.brut")
	if system("diff test.wzo test.brut"):
		print "ANS"
		break
	else: 	
		print "OK",i
		i=i+1

