//Code written for CS 341 at Butler University

#include "nonStandardDeck.h"
#include "standardDeck.h"

void checkDecks();
void earlyPhaseTests();
void printAll(Deck& a, Deck& b, Deck& c);
void phase4();
void phase5();

int main()
{
	/*War Algortithm, taken directly from the assignment pdf
	
	1.) Your Standard Deck will be built with 52 cards.
	2.) At the start of the game, each Player is dealt half of a deck of cards, which represents their army.
	3.) Each player alternates (e.g., p1, p2, p1, etc.) placing a card on top of a central pile called the
		battleground.
	4.) If the most recently played card matches the face of the card beneath it, that player takes all of the
			cards in the battleground and adds them to their army.
		a. For example, if Player 1 played a Jack of Spades on top of a Jack of Hearts, Player 1
			would collect all of the cards in the battleground and add them to their army.
	5.) The player who gained the reinforcements then plays the next card to start a new battleground.
	6.) Play continues in this way until only one player has cards left in their deck.
	7.) That player wins the round with a score equal to the number of cards in their current army.
	8.) In each round, Player 1 always plays the first card.
	
	*/
	
	phase5();
	
	phase4();
	
	
	
	return 0;
}
void phase5()
{
	//will be the average score of each player
	double player1AVG(0), player2AVG(0);
	int numGames(0), player1WinCount(0), player2WinCount(0);
	
	std::cout << "How many simulations to run? ";
	std::cin >> numGames;
	
	//will determine how much output the user wants
	bool constantOutput = false;
	char help(' ');
	
	std::cout << "Would you like full output (Y/N)? ";
	std::cin >> help;
	if(help == 'Y')
	{
		constantOutput = true;
	}
	//from now on, all output during a game will only execute if constantOutput is true
	
	
	//Start loop of games
	for(int j = 0; j < numGames; j++)
	{
		//creates decks for the common deck, and each hand
		NonStandardDeck battleground = NonStandardDeck();
		NonStandardDeck player1hand = NonStandardDeck();
		NonStandardDeck player2hand = NonStandardDeck();
		
		//start by initializing the battleground, and shuffling it
		battleground.initializeDeck();
		battleground.shuffle();
		
		if(battleground.getNumCards() % 2 == 1) //then the deck cannot be split evenly
		{
			//now split the main deck into the two hands     this part returns either a 1 or a 0 because the number is odd
			int stop = (battleground.getNumCards() / 2) + (rand() % 2);
			for(int i = 0; i < stop; i++)
			{
				player1hand.addCard(battleground.dealCard());
			}
		}
		else
		{
			//now split the main deck into the two hands
			int stop = (battleground.getNumCards() / 2);
			for(int i = 0; i < stop; i++)
			{
				player1hand.addCard(battleground.dealCard());
			}
		}
		
		//now half of deck is in player1hand, so the rest of the deck can be merged into player2hand, then deck will be emptied
		player2hand.mergeDecks(battleground);
		
		if(constantOutput)
		{	
			//print all the decks
			printAll(battleground,player1hand,player2hand);
		}
		
		//start gameplay loop
		int turn = 1; //1 means it is player1's turn, 2 means it is player2's turn
		while((player1hand.getNumCards() > 0) && (player2hand.getNumCards() > 0))
		{
			//player whose turn it is deals a card onto the main deck
			if(turn == 1)
			{
				if(constantOutput)
				{
					if (player1hand.getNumCards() < 10)
					{
						std::cout << "player1 (" << "0" << player1hand.getNumCards() << ") laid: ";
					}
					else
					{
						std::cout << "player1 (" << player1hand.getNumCards() << ") laid: ";
					}
				}
				battleground.addCard(player1hand.dealCard());
				if(constantOutput)
				{
					battleground.displayCard(battleground.getNumCards() - 1);
				}
			}
			else if(turn == 2)
			{
				if(constantOutput)
				{
					if (player2hand.getNumCards() < 10)
					{
						std::cout << "player2 (" << "0" << player2hand.getNumCards() << ") laid: ";
					}
					else
					{
						std::cout << "player2 (" << player2hand.getNumCards() << ") laid: ";
					}
				}
				battleground.addCard(player2hand.dealCard());
				if(constantOutput)
				{
					battleground.displayCard(battleground.getNumCards() - 1);
				}
			}
			
			//check to make sure there even is a card to compare to. Partly so that jokers don't get picked up after being laid on nothing
			//exclude 0, even though it will never be 0 here, as a player just laid a card
			//exlude 1 because if there is only one card on the battleground, the index below it doesn't exist.
			if(battleground.getNumCards() > 1)
			{
				//check if the card just dealt is the same as the last card dealt
				//           card just laid                                                  card previously laid
				if((battleground.getCard(battleground.getNumCards() - 1)).compareFace((battleground.getCard(battleground.getNumCards() - 2))))
				{
					//give the whole battleground to whoever just laid the card
					//whoever just went is meant to go next. I will change the turn here so that it will get changed again later
					//and therefore, the player who gained the battleground will go again.
					if(turn == 1)
					{
						player1hand.mergeDecks(battleground, true);
						if(constantOutput)
						{
							std::cout << "PLAYER 1 PICKED UP THE BATTLEGROUND" << std::endl;
						}
						turn = 2;
					}
					else if(turn == 2)
					{
						player2hand.mergeDecks(battleground, true);
						if(constantOutput)
						{
							std::cout << "PLAYER 2 PICKED UP THE BATTLEGROUND" << std::endl;
						}
						turn == 1;
					}
				}
			}
			
			//now change whose turn it is
			if(turn == 1)
			{
				turn = 2;
			}
			else if(turn = 2)
			{
				turn = 1;
			}
		}
		
		//since the while failed, the game is over, now the game can be evaluated, and scores added to the total
		
		//check who won
		if(player1hand.getNumCards() <= 0)
		{
			//player2 won, so add their score to their total
			player2AVG += player2hand.getNumCards();
			player2WinCount++;
		}
		else
		{
			//player1 won
			player1AVG += player1hand.getNumCards();
			player1WinCount++;
		}
		//averages will be divided by the number of games played later
		
	}
	
	
	
	//now that simulation is complete, compute the averages
	player1AVG /= player1WinCount;
	player2AVG /= player2WinCount;
	
	std::cout << "\n\n--------STATS--------\n\n" << std::endl;
	if(player1WinCount > player2WinCount)
	{
		std::cout << "player1 won more!" << std::endl;
	}
	else if(player1WinCount < player2WinCount)
	{
		std::cout << "player2 won more!" << std::endl;
	}
	else
	{
		std::cout << "player1 and player2 won the same amount of times!" << std::endl;
	}
	std::cout << "\tplayer1 won " << player1WinCount << " times." << std::endl;
	std::cout << "\tplayer2 won " << player2WinCount << " times." << std::endl;
	std::cout << "\tplayer1's average score:  " << player1AVG << std::endl;
	std::cout << "\tplayer2's average score:  " << player2AVG << std::endl;
}

void phase4()
{
	
	//will be the average score of each player
	double player1AVG(0), player2AVG(0);
	int numGames(0), player1WinCount(0), player2WinCount(0);
	
	std::cout << "How many simulations to run? ";
	std::cin >> numGames;
	
	//will determine how much output the user wants
	bool constantOutput = false;
	char help(' ');
	
	std::cout << "Would you like full output (Y/N)? ";
	std::cin >> help;
	if(help == 'Y')
	{
		constantOutput = true;
	}
	//from now on, all output during a game will only execute if constantOutput is true
	
	
	//Start loop of games
	for(int j = 0; j < numGames; j++)
	{
		//creates decks for the common deck, and each hand
		StandardDeck battleground = StandardDeck();
		StandardDeck player1hand = StandardDeck();
		StandardDeck player2hand = StandardDeck();
		
		//start by initializing the battleground, and shuffling it
		battleground.initializeDeck();
		battleground.shuffle();
		
		//now split the main deck into the two hands
		int stop = (battleground.getNumCards() / 2);
		for(int i = 0; i < stop; i++)
		{
			player1hand.addCard(battleground.dealCard());
		}
		//now half of deck is in player1hand, so the rest of the deck can be merged into player2hand, then deck will be emptied
		player2hand.mergeDecks(battleground);
		
		if(constantOutput)
		{	
			//print all the decks
			printAll(battleground,player1hand,player2hand);
		}
		
		//start gameplay loop
		int turn = 1; //1 means it is player1's turn, 2 means it is player2's turn
		while((player1hand.getNumCards() > 0) && (player2hand.getNumCards() > 0))
		{
			//player whose turn it is deals a card onto the main deck
			if(turn == 1)
			{
				if(constantOutput)
				{
					if (player1hand.getNumCards() < 10)
					{
						std::cout << "player1 (" << "0" << player1hand.getNumCards() << ") laid: ";
					}
					else
					{
						std::cout << "player1 (" << player1hand.getNumCards() << ") laid: ";
					}
				}
				battleground.addCard(player1hand.dealCard());
				if(constantOutput)
				{
					battleground.displayCard(battleground.getNumCards() - 1);
				}
			}
			else if(turn == 2)
			{
				if(constantOutput)
				{
					if (player2hand.getNumCards() < 10)
					{
						std::cout << "player2 (" << "0" << player2hand.getNumCards() << ") laid: ";
					}
					else
					{
						std::cout << "player2 (" << player2hand.getNumCards() << ") laid: ";
					}
				}
				battleground.addCard(player2hand.dealCard());
				if(constantOutput)
				{
					battleground.displayCard(battleground.getNumCards() - 1);
				}
			}
			
			//only check if there is actually a card below the one just laid
			if(battleground.getNumCards() > 1)
			{
				//check if the card just dealt is the same as the last card dealt
				//           card just laid                                                  card previously laid
				if((battleground.getCard(battleground.getNumCards() - 1)).compareFace((battleground.getCard(battleground.getNumCards() - 2))))
				{
					//give the whole battleground to whoever just laid the card
					//whoever just went is meant to go next. I will change the turn here so that it will get changed again later
					//and therefore, the player who gained the battleground will go again.
					if(turn == 1)
					{
						player1hand.mergeDecks(battleground, true);
						if(constantOutput)
						{
							std::cout << "PLAYER 1 PICKED UP THE BATTLEGROUND" << std::endl;
						}
						turn = 2;
					}
					else if(turn == 2)
					{
						player2hand.mergeDecks(battleground, true);
						if(constantOutput)
						{
							std::cout << "PLAYER 2 PICKED UP THE BATTLEGROUND" << std::endl;
						}
						turn == 1;
					}
				}
			}
			
			//now change whose turn it is
			if(turn == 1)
			{
				turn = 2;
			}
			else if(turn = 2)
			{
				turn = 1;
			}
		}
		
		//since the while failed, the game is over, now the game can be evaluated, and scores added to the total
		
		//check who won
		if(player1hand.getNumCards() <= 0)
		{
			//player2 won, so add their score to their total
			player2AVG += player2hand.getNumCards();
			player2WinCount++;
		}
		else
		{
			//player1 won
			player1AVG += player1hand.getNumCards();
			player1WinCount++;
		}
		//averages will be divided by the number of games played later
		
	}
	
	
	
	//now that simulation is complete, compute the averages
	player1AVG /= player1WinCount;
	player2AVG /= player1WinCount;
	
	std::cout << "\n\n--------STATS--------\n\n" << std::endl;
	if(player1WinCount > player2WinCount)
	{
		std::cout << "player1 won more!" << std::endl;
	}
	else if(player1WinCount < player2WinCount)
	{
		std::cout << "player2 won more!" << std::endl;
	}
	else
	{
		std::cout << "player1 and player2 won the same amount of times!" << std::endl;
	}
	std::cout << "\tplayer1 won " << player1WinCount << " times." << std::endl;
	std::cout << "\tplayer2 won " << player2WinCount << " times." << std::endl;
	std::cout << "\tplayer1's average score:  " << player1AVG << std::endl;
	std::cout << "\tplayer2's average score:  " << player2AVG << std::endl;
	
}


void printAll(Deck& a, Deck& b, Deck& c)
{
	
	std::cout << "Battleground (" << a.getNumCards() << "): " << std::endl;
	a.printDeck();
	std::cout << "\nplayer1hand (" << b.getNumCards() << "): " << std::endl;
	b.printDeck();
	std::cout << "\nplayer2hand (" << c.getNumCards() << "): " << std::endl;
	c.printDeck();
	std::cout << "\n\n" << std::endl;
	
}


void checkDecks(StandardDeck deck)
{
	/*
	//now check
	std::cout << "deck: " << std::endl;
	deck.printDeck();
	std::cout << "\n\nplayer1hand: " << std::endl;
	player1hand.printDeck();
	std::cout << "\n\nplayer2hand: " << std::endl;
	player2hand.printDeck();
	*/
}
void earlyPhaseTests(StandardDeck deck, StandardDeck deck1)
{
	/*
	StandardDeck deck = StandardDeck();
	StandardDeck deck1 = StandardDeck();
	//deck.initializeDeck();
	
	Card a = Card(1,4);
	Card b = Card(2,3);
	Card c = Card(2,2);
	
	Card a1 = Card(4,3);
	Card b1 = Card(2,10);
	Card c1 = Card(3,7);
	
	deck.addCard(a);
	deck.addCard(b);
	deck.addCard(c);
	
	deck1.addCard(a1);
	deck1.addCard(b1);
	deck1.addCard(c1);
	
	deck.printDeck();
	std::cout << "\n" << std::endl;
	deck1.printDeck();

	std::cout << "Now Merge:" << std::endl;
	
	deck.mergeDecks(deck1, true);
	deck.printDeck();
	std::cout << "\n\n" << std::endl;
	
	
	std::cout << "Now Shuffle: " << std::endl;
	deck.shuffle();
	deck.printDeck();
	std::cout << "\n\n" << std::endl;
	
	
	
	
	std::cout << "isEmpty(): " << deck.isEmpty() << std::endl;
	std::cout << "getNumCards(): " << deck.getNumCards() << std::endl;
	std::cout << "displayCard(15): ";
	deck.displayCard(15);
	std::cout << "printDeck(): \n";
	

	//delete deck;
	//delete deck1;
	*/
}