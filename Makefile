exe: implement.o execute.o
	gcc -o exe driver.c implement.o execute.o
implement.o:
	gcc -c implementation.c -o implement.o
execute.o:
	gcc -c execute_single.c -o execute.o
	
