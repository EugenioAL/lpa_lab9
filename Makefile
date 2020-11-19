lab9:	main.o myFile.o  
		gcc main.c myFile.c -o lab9

main.o: main.c myFile.c
		gcc -c main.c

myFile.o: myFile.c myLib.h
		gcc -c myFile.c


run:
	./lab9 leon.mpg 18
clear:
	rm -rf *.exe
	rm -rf *.out
	rm -rf *.o