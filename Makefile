
all:	main.o
		g++ main.o -o main -lcurl

main.o: main.cpp
		g++ -c main.cpp

clean:
		rm -rf *o main