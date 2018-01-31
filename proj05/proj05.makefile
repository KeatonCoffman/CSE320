
all: proj05.driver.o proj05.support.o
	gcc proj05.driver.o proj05.support.o /user/cse320/lib/bitlib.o \
             -o proj05

proj05.support.o: proj05.support.c /user/cse320/Projects/project05.support.h
	gcc -Wall -c proj05.support.c

proj05.driver.o: proj05.driver.c /user/cse320/Projects/project05.support.h
	gcc -Wall -c proj05.driver.c
