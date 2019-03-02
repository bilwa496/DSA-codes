run : compile
	./out
	#gdb ./out 1000 
compile : records.o driver.o
	gcc -g fread.o implArray.o insert.o test.o frtest.o -o out
driver.o : driver.c record.h
	gcc -c -g driver.c
records.o : records.c record.h
	gcc -c -g records.c
