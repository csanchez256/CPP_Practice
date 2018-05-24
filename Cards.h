#pragma once

/*
file: Cards.h
*/
enum SUIT {
	CLUB,
	DIAMOND,
	HEART,
	SPADE,
	SUIT_CEILING
};

enum RANK {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	RANK_CEILING
};

struct CARD {
	RANK rank;
	SUIT suit;
};

void swapCard(CARD &card1, CARD &card2);

void shuffleDeck(std::array<CARD, 52> &cardArray);

void printCard(const CARD &card);

void printDeck(const std::array<CARD, 52> &cardArray);

int getCardValue(const CARD &card);

void playBlackJack(std::array<CARD, 52> &cardArray);

int dealCards(std::array<CARD, 52> &cardArray, int);

std::string determineWinner(int, int);

void printScore(int, int);