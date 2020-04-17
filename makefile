gofish: go_fish.o card.o deck.o player.o
	g++ go_fish.o card.o deck.o player.o -o gofish
	
go_fish.o: go_fish.cpp
	g++ -c go_fish.cpp
	
card.o: card.cpp
	g++ -c card.cpp
	
deck.o: deck.cpp
	g++ -c deck.cpp
	
player.o: player.cpp
	g++ -c player.cpp
	
clean:
	rm *.o math