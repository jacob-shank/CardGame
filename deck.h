//Code written for CS 341 at Butler University
//Header file provided by Dr. Ryan Rybarcyzk

#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck
{
	public:
		//constructors and destructor
		Deck();
		//Deck(Deck d);
		virtual ~Deck();
	
//other necessary deck funtions. The following functions require a value passed or a constant other than an attribute of the class to be implemented
	
		//fills the deck with the standard cards
		virtual void initializeDeck()=0;
		
		//adds a card to the deck, returns true if it was successful
		virtual bool addCard(Card c)=0;
		
		//combines decks
		virtual bool mergeDecks(Deck&,bool b = false)=0;
	
//functions that are not virtual, the following functions are implemented only using attributes of the class
	
		//returns te card with highest index
		Card dealCard();
		
		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		bool isEmpty();	

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void printDeck();
		
		
		//makes the deck empty
		void makeEmpty();
		
		//mixes up the order of the cards randomly
		void shuffle();
		
		
		//returns a given card
		Card getCard(int i);
	
	//protected: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;	// Stores the number of Cards currently in the deck.
	
};


#endif