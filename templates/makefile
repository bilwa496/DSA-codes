run : compileAll
	./myprogram
compileAll : module1.o module2.o driver.o
gcc module1.o module2.o driver.o -o myprogram
module1.o : module1.c module1.h
gcc -c module1.c
module2.o : module2.c module2.h
gcc -c module2.c
driver.o : driver.c module1.h module2.h
gcc -c driver.c