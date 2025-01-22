Cards.exe: card.o deck.o standardDeck.o nonStandardDeck.o driver.o
	g++ driver.o card.o deck.o standardDeck.o nonStandardDeck.o -o Cards.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
standardDeck.o: standardDeck.cpp
	g++ -c standardDeck.cpp -o standardDeck.o

nonStandardDeck.o: nonStandardDeck.cpp
	g++ -c nonStandardDeck.cpp -o nonStandardDeck.o

deck.o: deck.cpp
	g++ -c deck.cpp -o deck.o

card.o: card.cpp
	g++ -c card.cpp -o card.o