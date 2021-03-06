#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Cards.h"

/*
file: cards.cpp
*/

std::array <CARD, 52> cardArray;

// not actually swapping the array elements in memory
void swapCard(CARD &card1, CARD &card2) {
	CARD temp = card1;
	card1 = card2;
	card2 = temp;
}

void shuffleDeck(std::array<CARD, 52> &cardArray) {
	time_t srand(time(NULL));

	for (int i = 0; i < 52; ++i)
	{
		int randm;
		randm = (rand() % 51);                    //random number between 0 and 51
		swapCard(cardArray[i], cardArray[randm]);
	}
}

void printCard(const CARD &card) {

	switch (card.rank) {
	case TWO:	std::cout << "2";  break;
	case THREE:	std::cout << "3";  break;
	case FOUR:  std::cout << "4";  break;
	case FIVE:  std::cout << "5";  break;
	case SIX:   std::cout << "6";  break;
	case SEVEN: std::cout << "7";  break;
	case EIGHT: std::cout << "8";  break;
	case NINE:  std::cout << "9";  break;
	case TEN:   std::cout << "10"; break;
	case JACK:  std::cout << "J";  break;
	case QUEEN: std::cout << "Q";  break;
	case KING:  std::cout << "K";  break;
	case ACE:   std::cout << "A";  break;
	}

	switch (card.suit) {
	case CLUB:    std::cout << "C"; break;
	case DIAMOND: std::cout << "D"; break;
	case HEART:   std::cout << "H"; break;
	case SPADE:   std::cout << "S"; break;
	}
	std::cout << '\n';
}

void printDeck(const std::array<CARD, 52> &cardArray) {
	int counter = 1;
	for (const auto &c : cardArray) {
		printCard(c);
		++counter;
	}
	std::cout << '\n';
}

int getCardValue(const CARD &card) {
	switch (card.rank) {
		case TWO:	 return 2;
		case THREE:	 return 3;
		case FOUR:   return 4;
		case FIVE:   return 5;
		case SIX:    return 6;
		case SEVEN:  return 7;
		case EIGHT:  return 8;
		case NINE:   return 9;
		case TEN:    return 10;
		case JACK:   return 10;
		case QUEEN:  return 10;
		case KING:   return 10;
		case ACE:    return 11;
	}
	return 0;
}

void playBlackJack(std::array<CARD, 52> &cardArray) {
	int ptr_index = 0;
	while (1) {
		std::cout << "Play a round of Black Jack? y/n " << std::endl;
		char answer;
		std::cin >> answer;
		if (answer == 'y') ptr_index = dealCards(cardArray,ptr_index);
		if (answer == 'n') { std::cout << "Good bye!" << std::endl; return; }
	}
}

int dealCards(std::array<CARD, 52> &cardArray, int ptr_index) {
	CARD *cardPtr = &cardArray[ptr_index];
	int playerScore = 0;
	int dealerScore = 0;
	bool hit = true;

	while (hit) {
		playerScore += getCardValue(*cardPtr++);
		++ptr_index;
		playerScore += getCardValue(*cardPtr++);
		++ptr_index;

		dealerScore += getCardValue(*cardPtr++);
		++ptr_index;

		printScore(playerScore, dealerScore);

		if(checkBustedHand(playerScore, dealerScore) == true) return ptr_index;

		char answer;
		std::cout << "Do you want to hit? y/n" << std::endl;
		std::cin >> answer;
		if (answer == 'y') hit = true;
		else if (answer == 'n') {
			while (dealerScore <= 16) { 
				dealerScore += getCardValue(*cardPtr++); 
				++ptr_index;
			}

			if (checkBustedHand(playerScore, dealerScore) == true) return ptr_index;

			else {
				std::cout << determineWinner(playerScore, dealerScore) << std::endl;
				printScore(playerScore, dealerScore);
				return ptr_index;
			}
		}
		else return ptr_index;
	}
}

bool checkBustedHand(int playerScore, int dealerScore) {
	if (playerScore > 21) {
		std::cout << "**Player bust! You lose!" << std::endl;
		return true;
	}
	if (dealerScore > 21) {
		std::cout << "**Dealer bust! You win!" << std::endl;
		return true;
	}
}
std::string determineWinner(int playerScore, int dealerScore) {
	if      (playerScore > dealerScore)  return "**You win!";
	else if (playerScore < dealerScore)  return "**Dealer wins ";
	else if (playerScore == dealerScore) return "**Split";
	return " ";
}

void printScore(int playerScore, int dealerScore) {
	std::cout << "<your hand> " << playerScore << std::endl;
	std::cout << "<dealer's hand> " << dealerScore << std::endl;
}