from os import system
import time
i=50
while i:
	system("./gen_kom > in.in")
	system("time ./kom < in.in > kom.out")
	system("time ./kom2 < in.in > kom2.out")
	system("diff -sq  kom.out kom2.out")
	i=i-1
	time.sleep(1)
	print "\n"
