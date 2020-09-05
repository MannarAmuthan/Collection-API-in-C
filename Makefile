TOOLCHAIN = gcc
CC = $(TOOLCHAIN)
OBJCOPY = $(TOOLCHAIN)-objcopy
GDB = $(TOOLCHAIN)-gdb

build: sourcefiles/ArrayList.c sourcefiles/Comparator.c sourcefiles/HashMap.c sourcefiles/Iterable.c sourcefiles/LinkedList.c sourcefiles/PriorityQueue.c sourcefiles/Set.c sourcefiles/Stack.c
	$(CC) -g -O -c sourcefiles/ArrayList.c sourcefiles/Comparator.c sourcefiles/HashMap.c sourcefiles/Iterable.c sourcefiles/LinkedList.c sourcefiles/PriorityQueue.c sourcefiles/Set.c sourcefiles/Stack.c
	ar rc libcollection.a ArrayList.o Comparator.o HashMap.o Iterable.o LinkedList.o PriorityQueue.o Set.o Stack.o
	rm ArrayList.o Comparator.o HashMap.o Iterable.o LinkedList.o PriorityQueue.o Set.o Stack.o

compile: main.c
	$(CC) main.c -o hello libcollection.a