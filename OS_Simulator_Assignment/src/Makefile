
output : driver.o linkedlist.o interface.o
	gcc driver.o linkedlist.o interface.o -o output
	./output
driver.o:driver.c
	gcc -c driver.c
linkedlist.o:linkedlist.c linkedlist.h
	gcc -c linkedlist.c
interface.o:interface.c interface.h
	gcc -c interface.c
clean:
	rm *.o output