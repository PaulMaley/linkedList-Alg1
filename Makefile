linkedList.o : linkedList.c linkedList.h
	gcc -c linkedList.c

myList.o : myList.c linkedList.h
	gcc -c myList.c

myList : myList.o linkedList.o
	gcc -o myList -Wall myList.o linkedList.o

