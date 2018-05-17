#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "SwapIntegers.h"
#include "pointer_Array_Practice.h"


struct STUDENTS {
	std::string NAME;
	int GRADE;
};

void printStudents(int numStudents, STUDENTS *sArray) {
	STUDENTS s;
	for (int j = 0; j < numStudents; ++j) {
		s = sArray[j];
		std::cout << s.NAME << " got a grade of " << s.GRADE << std::endl;
	}
}

void sortStudents(int numStudents, STUDENTS *sArray) {
	for (int startIndex = 0; startIndex < numStudents - 1; ++startIndex) {
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < numStudents; ++currentIndex) {
			STUDENTS s1 = sArray[currentIndex];
			STUDENTS s2 = sArray[smallestIndex];
			if (s1.GRADE > s2.GRADE) {
				smallestIndex = currentIndex;
			}
			std::swap(sArray[startIndex], sArray[smallestIndex]);
		}
	}
	printStudents(numStudents, sArray);
}


void roster() {
	std::cout << "How many student names do you want to enter? " << std::endl;
	int numStudents;
	std::cin >> numStudents;

	STUDENTS *sArray = new STUDENTS[numStudents];

	std::cout << "Enter name of student and grade " << std::endl;

	int i;
	for (i = 0; i < numStudents; ++i) {

		std::string name;
		std::cin >> name;
		std::cin.ignore(32767, '\n'); //read in this many characters up to the newline

		int grade;
		std::cin >> grade;

		STUDENTS s;
		s.NAME = name;
		s.GRADE = grade;

		sArray[i] = s;
	}
	sortStudents(numStudents, sArray);
}

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

// re-write your swap function
void swapCard(CARD &card1, CARD &card2) {
	CARD temp = card1;
	card1 = card2;
	card2 = temp;
}


void shuffleDeck(const std::array<CARD, 52> &cardArray) {
	CARD card1, card2;
	for (int i = 0; i < 52; ++i) 
	{
		srand((unsigned)time(0));      // needs <ctime>
		int randm;
		randm = (rand() % 51);         //random number between 0 and 51

		card1 = cardArray[i];
		card2 = cardArray[randm];
		swapCard(card1,card2);
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
		case TEN: std::cout << '10'; break;
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
	std::cout << '\n';

	std::array <CARD, 52> cardArray;



	// tip: you can treat an enumerated type as a number
	//tip cardArray is just an array that can access two things

	for (int i = 0; i < RANK_CEILING; ++i) {
		for (int j = 0; j < SUIT_CEILING; ++j) {
			cardArray[i].rank = static_cast<RANK>(i);
			cardArray[j].suit = static_cast<SUIT>(j);
		}
	}
	//printDeck(cardArray);
	shuffleDeck(cardArray);
}

void printDeck(const std::array<CARD,52> &cardArray) {
	for (const auto &c : cardArray) {
		printCard(c);
	}
}


int main()
{

	swap(1,2);
	CARD c;
	c.rank = TWO;
	c.suit = SPADE;
	printCard(c);

	CARD b;
	b.rank = SIX;
	b.suit = CLUB;

	swapCard(c,b);

    return 0;
}

