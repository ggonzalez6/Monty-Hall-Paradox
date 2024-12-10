CC = g++
CFLAGS = -g -Wall -Wextra


default: paradox


paradox: main.o
	$(CC) $(CFLAGS) -o paradox main.o

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp


clean:
	$(RM) *.o *~
