//Code written for CS 341 at Butler University


#include "deck.h"
//default constructor
Deck::Deck(): numCards_(0)
{

}
//destructor
Deck::~Deck()
{
	delete [] deck_;
}

//returns card with highest index
Card Deck::dealCard()
{
	/*if(numCards_ > 0)
	{
		return deck_[numCards_ - 1];
		numCards_--;
	}
	else
	{
		return nullptr;
	}*/
	
	numCards_--;
	//not numCards_ - 1 because I already decreased it.
	return deck_[numCards_];
}
//returns true when the current deck is empty
bool Deck::isEmpty()
{
	if(numCards_ > 0)
	{
		return false;
	}
	return true;
}
//getter
int Deck::getNumCards()
{
	return numCards_;
}
//prints out the information on a card in the current deck
void Deck::displayCard(int i)
{
	std::cout << deck_[i].print() << std::endl;
}
//displays the whole deck
void Deck::printDeck()
{
	for(int i = 0; i < numCards_; i++)
	{
		std::cout << deck_[i].print() << std::endl;
	}
}
//makes the deck empty
void Deck::makeEmpty()
{
	numCards_ = 0;
}
//randomly orders the deck
void Deck::shuffle()
{
	std::default_random_engine randNum(std::random_device{}());
	std::shuffle(deck_, deck_+numCards_, randNum);
}
Card Deck::getCard(int i)
{
	return deck_[i];
}