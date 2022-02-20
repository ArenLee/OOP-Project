make all: tests Project

Project: main.cpp Card.o Deck.o Character.o Player.o GameSystem.o Randy.o Cutter.o Numbers.o
	g++ main.cpp Card.o Deck.o Character.o Player.o GameSystem.o Randy.o Cutter.o Numbers.o -o Project

Character.o: Character.h Character.cpp
	g++ -c Character.cpp

Player.o: Player.h Player.cpp
	g++ -c Player.cpp

Randy.o: Randy.h Randy.cpp
	g++ -c Randy.cpp

Cutter.o: Cutter.h Cutter.cpp
	g++ -c Cutter.cpp

Numbers.o: Numbers.h Numbers.cpp
	g++ -c Numbers.cpp

Card.o: Card.h Card.cpp
	g++ -c Card.cpp

Deck.o: Deck.h Deck.cpp
	g++ -c Deck.cpp

GameSystem.o: GameSystem.h GameSystem.cpp
	g++ -c GameSystem.cpp

tests: DeckTest PlayerTest GameSystemTest
	./DeckTest
	./PlayerTest < PlayerTestInput.txt | diff - PlayerTestOutput.txt
	./GameSystemTest

DeckTest: DeckDriver.cpp Deck.o Card.o
	g++ DeckDriver.cpp Card.o Deck.o -o DeckTest

PlayerTest: PlayerDriver.cpp Card.o Deck.o Character.o Player.o
	g++ PlayerDriver.cpp Card.o Deck.o Character.o Player.o -o PlayerTest

GameSystemTest: GameDriver.cpp Card.o Deck.o Character.o Player.o GameSystem.o Randy.o Cutter.o Numbers.o
	g++ GameDriver.cpp Card.o Deck.o Character.o Player.o GameSystem.o Randy.o Cutter.o Numbers.o -o GameSystemTest

clean:
	rm -f *.o project
