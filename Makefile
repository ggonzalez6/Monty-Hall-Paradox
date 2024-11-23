CC = g++
CFLAGS = -g -Wall -Wextra


default: paradox


paradox: hall.o main.o
	$(CC) $(CFLAGS) -o paradox hall.o main.o


hall.o: hall.cpp hall.h
	$(CC) $(CFLAGS) -c hall.cpp


main.o: main.cpp hall.h
	$(CC) $(CFLAGS) -c main.cpp


clean:
	$(RM) *.o *~
