all: woOram

woOram: client.o woOram.o 
	g++ client.o woOram.o -o target

client.o: client.cpp
	g++ -c client.cpp

woOram.o: woOram.cpp
	g++ -c woOram.cpp

clean: 
	rm -rf *o woOram

