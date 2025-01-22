//Code written for CS 341 at Butler University

#include "standardDeck.h"

StandardDeck::StandardDeck(): Deck()
{
	deck_ = new Card[DECK_SIZE];
}
//default destructor -- will run the deck destructor by default, and the delete the Card array, which is on the heap.
StandardDeck::~StandardDeck()
{
	
}
//copy constuctor
StandardDeck::StandardDeck(const StandardDeck & deck)
{
	for(int i = 0; i < numCards_; i++)
	{
		deck_[i] = deck.deck_[i];
	}
	numCards_ = deck.numCards_;
}
//fills deck withe the standard cards
void StandardDeck::initializeDeck()
{
	//now fill the array with the standard cards, code pulled straight from driver.cpp after phase 1
	
	
	//to make a standard deck, the suit needs to increase every 13 iterations
	// and the suit needs to increase every iteration, reseting at 13
	int faceCount(1), suitCount(1); //start at one bc a standard deck does not have elements of card.FACE[] or card.SUIT[]
	for(int i = 0; i < DECK_SIZE; i++)
	{
		deck_[i] = Card(suitCount,faceCount);
		numCards_++;
		
		//face count goes up everytime unless it needs to reset, every time it does so, suitCount goes up
		if(faceCount == 13)
		{
			suitCount++;
			faceCount = 1;
		}
		else
		{
			faceCount++;
		}
	}
	
	//at this point in the function, deck_ points to an array full of the standard deck of cards.
}
//adds a card to the deck, returns true if successful
bool StandardDeck::addCard(Card c)
{
	if((numCards_ < DECK_SIZE) && (numCards_ >= 0))
	{
		deck_[numCards_] = c;
		numCards_++;
		
		return true;
	}
	return false;
}
//amends the given deck to the current deck, can shuffle after depending on b
bool StandardDeck::mergeDecks(Deck & deck,bool b)
{
	//will be changed to true if even a single card can be added to the deck
	bool returnable = false;
	
	//adds the first card in the inputted deck to the end of the current deck until either the inputted deck is empty or the current deck is full
	int i = 0, stop = deck.numCards_;
	while((numCards_ < DECK_SIZE) && (i < stop)) //(current deck is not full) && (given deck still has cards)
	{
		deck_[numCards_] = deck.deck_[i];
		returnable = true;
		i++;
		numCards_++;
		//removes the card from the deck that is being mergred out of
		deck.numCards_--;
	}
	
	if(b)
	{
		//shuffles this
		shuffle();
	}
	return returnable;
}
