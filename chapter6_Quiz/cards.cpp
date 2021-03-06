#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <ctime>
#include <cstdlib>


#include "Cards.h"

std::array <CARD, 52> cardArray;

// not actually swapping the array elements in memory
void swapCard(CARD &card1, CARD &card2) {
	CARD temp = card1;
	card1 = card2;
	card2 = temp;
}


void shuffleDeck( std::array<CARD, 52> &cardArray) {
	srand(time(NULL));

	for (int i = 0; i < 52; ++i)
	{
		int randm;
		randm = (rand() % 52);         //random number between 0 and 51
		swapCard(cardArray[i], cardArray[randm]);
	}
}


void printCard(const CARD &card) {

	switch (card.rank) {
	case TWO:	std::cout << '2'; break;
	case THREE:	std::cout << '3'; break;
	case FOUR: std::cout << '4'; break;
	case FIVE: std::cout << '5'; break;
	case SIX: std::cout << '6'; break;
	case SEVEN: std::cout << '7'; break;
	case EIGHT: std::cout << '8'; break;
	case NINE: std::cout << '9'; break;
	case TEN: std::cout << "10"; break;
	case JACK: std::cout << 'J'; break;
	case QUEEN: std::cout << 'Q'; break;
	case KING: std::cout << 'K'; break;
	case ACE: std::cout << 'A'; break;
	}

	switch (card.suit) {
	case CLUB: std::cout << 'C'; break;
	case DIAMOND: std::cout << 'D'; break;
	case HEART: std::cout << 'H'; break;
	case SPADE: std::cout << 'S'; break;
	}
	//std::cout << " ";
	std::cout << '\n';
}

void printDeck(const std::array<CARD, 52> &cardArray) {
	int counter = 1;
	for (const auto &c : cardArray) {
		std::cout << counter << " .) ";
		printCard(c);
		++counter;
	}
	std::cout << '\n';
}

