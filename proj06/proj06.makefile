proj06: proj06.support.o proj06.driver.o 
	gcc proj06.support.o proj06.driver.o -o proj06

proj06.support.o: proj06.support.c /user/cse320/Projects/project06.support.h
	gcc -Wall -c proj06.support.c

proj06.driver.o: proj06.driver.c /user/cse320/Projects/project06.support.h
	gcc -Wall -c proj06.driver.c

