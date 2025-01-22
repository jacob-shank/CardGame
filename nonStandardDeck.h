//Code written for CS 341 at Butler University

#ifndef NONSTANDARDDECK_H
#define NONSTANDARDDECK_H

#include "deck.h"

//can have any size, will get info from a text file.
class NonStandardDeck : public Deck
{
	public:
		//constructor.destructor
		NonStandardDeck();
		~NonStandardDeck();
		
		//copy constructor
		NonStandardDeck(const NonStandardDeck& nsd);
		
	//virtuals from Deck
		void initializeDeck();
		bool addCard(Card c);
		bool mergeDecks(Deck&,bool b = false);
		
	private:
		//will be used to read through the file. Defined as an attribute of the class so that any method can
		//use it, and it will be in the same spot
		std::fstream reader_;
		int deckSize_;
};

#endif