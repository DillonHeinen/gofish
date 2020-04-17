gofish: go_fish.o card.o deck.o player.o
	g++ -std=c++0x go_fish.o card.o deck.o player.o -o gofish
	
go_fish.o: go_fish.cpp
	g++ -std=c++0x -c go_fish.cpp
	
card.o: card.cpp
	g++ -std=c++0x -c card.cpp
	
deck.o: deck.cpp
	g++ -std=c++0x -c deck.cpp
	
player.o: player.cpp
	g++ -std=c++0x -c player.cpp
	
clean:
	rm *.o gofish