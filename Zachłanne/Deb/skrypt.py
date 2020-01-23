from os import system
i=1
while 1:
	system("./gen > test.in")
	system("./D1 <test.in>test.wzo")
	system("./brut<test.in>test.brut")
	if system("diff -w test.wzo test.brut"):
		break
	else:
		print "OK",i
	i=i+1
