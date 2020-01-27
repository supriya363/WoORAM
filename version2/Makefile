all: woOram

woOram: client.o woOram.o utility.o 
	g++ client.o woOram.o woram_utility.o -o target

client.o: client.cpp
	g++ -c client.cpp

woOram.o: woOram.cpp
	g++ -c woOram.cpp

utility.o: woram_utility.cpp
	g++ -c woram_utility.cpp

clean: 
	rm -rf *o woOram

