OBJS = main.o Tests.o
CC = g++
CFLAGS = -Wall -std=c++11 -c
LFLAGS = -Wall -std=c++11

all : rbtree

debug : CFLAGS += -g
debug : LFLAGS += -g
debug : rbtree

rbtree : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o rbtexec

main.o : main.cpp tests.h
	$(CC) $(CFLAGS) main.cpp

Tests.o : Tests.h Tests.cpp RBTree.h
	$(CC) $(CFLAGS) Tests.cpp

clean:
	\rm *.o *~ rbtexec