//Code written for CS 341 at Butler University

#include "nonStandardDeck.h"

//Constructor
NonStandardDeck::NonStandardDeck(): Deck()
{
	reader_.open("deck.txt");
	
	//gets the first line of deck.txt, then converts it into an int, and puts it into deckSize_
	std::stringstream converter;
	std::string line("");
	
	//gets the first line from the file
	std::getline(reader_,line);
	
	converter.clear();
	converter.str("");
	converter << line;
	converter >> deckSize_;
	
	//now that we know the deck size, we can instantiate the deck array
	deck_ = new Card[deckSize_];
	
}

//destructor -- will run deck destrucor by default, which takes care of everything on the heap
NonStandardDeck::~NonStandardDeck()
{
	reader_.close();
}

//Copy Constructor
NonStandardDeck::NonStandardDeck(const NonStandardDeck & nsd)
{
	for(int i = 0; i < numCards_; i++)
	{
		deck_[i] = nsd.deck_[i];
	}
	numCards_ = nsd.numCards_;
}

//fills the deck with the cards specified in deck.txt
void NonStandardDeck::initializeDeck()
{
	std::stringstream converter;
	converter.clear();
	converter.str("");
	
	std::string line(""),suit(""),face("");
	int suitInt(0), faceInt(0);
	
	//second boolean is in case the text file is too long
	while((!reader_.eof()) && (numCards_ <= deckSize_))
	{
		std::getline(reader_,line);
		suit = line.substr(0,1); //should return the first character of the string
		face = line.substr(2,2); //should return the third character of the string
									//2 is intentionally larger than the size of line
									//so that it will return everything to the end of the string
									//Since line was read in using the eol character as delimiter,
									//that character is not at the end of line. Therefore, the substr()
									//will read to end, this way, it accounts for any 2 digit numbers
				
		//now convert them both to ints
		converter.clear();
		converter.str("");
		
		converter << suit;
		converter >> suitInt;
		
		converter.clear();
		converter.str("");
		
		converter << face;
		converter >> faceInt;
		
		//now add the card to the deck.
		deck_[numCards_] = Card(suitInt,faceInt);
		numCards_++;
	}
	
	//resets the reader so that the deck can be initialized again
	reader_.close();
	reader_.open("deck.txt");
	std::getline(reader_, line); //now the cursur is at the start of the second line for the next initialization
}

//appends a card onto the deck
bool NonStandardDeck::addCard(Card c)
{
		if((numCards_ < deckSize_) && (numCards_ >= 0))
	{
		deck_[numCards_] = c;
		numCards_++;
		
		return true;
	}
	return false;
}

//merges two decks together
bool NonStandardDeck::mergeDecks(Deck& deck,bool b)
{
	//will be changed to true if even a single card can be added to the deck
	bool returnable = false;
	
	//adds the first card in the inputted deck to the end of the current deck until either the inputted deck is empty or the current deck is full
	int i = 0, stop = deck.numCards_;
	while((numCards_ < deckSize_) && (i < stop)) //(current deck is not full) && (given deck still has cards)
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