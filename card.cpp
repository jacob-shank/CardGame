//Code written for CS 341 at Butler University

#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card(): suitVal_(0), faceVal_(0)
{
	
}
Card::Card(int s, int f)
{
	suitVal_ = s;
	faceVal_ = f;
}
Card::~Card()
{
	
}
void Card::initialize(int s, int f)
{
	suitVal_ = s;
	faceVal_ = f;
}
bool Card::equals(Card c)
{
	if((suitVal_ == c.getSuitVal()) && (faceVal_ == c.getFaceVal()))
	{
		return true;
	}
	return false;
}
bool Card::compareFace(Card c)
{
	if(faceVal_ == c.getFaceVal())
	{
		return true;
	}
	return false;
}
bool Card::compareSuit(Card c)
{
	if(suitVal_ == c.getSuitVal())
	{
		return true;
	}
	return false;
}
std::string Card::print()
{
	int numSpaces = 0;
	
	//num spaces is now the right number of spaces to put after the face so that all the "of"s line up in the terminal
	numSpaces = 7 - FACE[faceVal_].length();
	
	//now build a string using numSpaces
	std::string line = "";
	line += FACE[faceVal_];
	
	//now add the appropriate number of spaces
	for(int i = 0; i < numSpaces; i++)
	{
		line += " ";
	}
	
	//now add the "of," followed by the suit
	line += "of  " + SUIT[suitVal_];
	
	return line;
}


//getters and setters
std::string Card::getSuit()
{
	return SUIT[suitVal_];
}
std::string Card::getFace()
{
	return FACE[faceVal_];
}
int Card::getSuitVal()
{
	return suitVal_;
}
int Card::getFaceVal()
{
	return faceVal_;
}

