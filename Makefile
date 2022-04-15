main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o -std=c++11

tests: tests.o profile.o network.o
	g++ -std=c++11 -o tests tests.o profile.o network.o -std=c++11

main.o: main.cpp profile.h network.h
	g++ -c main.cpp

network.o: network.cpp network.h
	g++ -std=c++11 -c network.cpp

profile.o: profile.cpp profile.h
	g++ -c profile.cpp

tests.o: tests.cpp doctest.h
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f main tests main.o profile.o network.o tests.o 