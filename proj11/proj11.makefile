proj11: proj11.support.o proj11.driver.o 
	gcc proj11.support.o proj11.driver.o /user/cse320/lib/bitlib.h \
		-o proj11

proj11.support.o: proj11.support.c /user/cse320/Projects/project11.support.h
	gcc -Wall -c proj11.support.c

proj11.driver.o: proj11.driver.c /user/cse320/Projects/project11.support.h
	gcc -Wall -c proj11.driver.c
