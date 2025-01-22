//Code written for CS 341 at Butler University

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include "deck.h"

#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck : public Deck
{
	public:
		/// Default constructor.
		StandardDeck();
		
		/// Default destructor.
		~StandardDeck();
		
		//copy constructor
		StandardDeck(const StandardDeck&);
		
		//fills the deck with the standard cards
		void initializeDeck() /*override*/;
		
		//adds a card to the deck, returns true if it was successful
		bool addCard(Card c) /*override*/;
		
		//combines decks
		bool mergeDecks(Deck&,bool b = false) /*override*/;
		
		//inherited from Deck
	/*protected: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;	// Stores the number of Cards currently in the deck.*/
};

#endif