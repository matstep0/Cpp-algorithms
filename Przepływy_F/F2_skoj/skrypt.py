from os import system
i=1
while i:
	system("./gen >test.in")
	system("./F2 <test.in> test.moj")
	system("./Janeczko<test.in> test.wzo")
	if system("diff -q test.wzo test.moj"):
		print "ANS" 
		break
	else:
		print "OK", i
		i=i+1
 
