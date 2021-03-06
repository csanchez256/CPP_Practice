#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "SwapIntegers.h"
#include "Cards.h"


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



int main()
{
	std::array <CARD, 52> cardArray;

	/*
	tip: you can treat an enumerated type as a number
	tip: cardArray is just an array that can access two things
	*/

	// initialize the array

	int index = 0;
	for (int i = 0; i < SUIT_CEILING; ++i) {
		for (int j = 0; j < RANK_CEILING; ++j) {
			cardArray[index].suit = static_cast<SUIT>(i);
			cardArray[index].rank = static_cast<RANK>(j);
			++index;
		}
	}

	printDeck(cardArray);

	shuffleDeck(cardArray);

	printDeck(cardArray);

	CARD c;
	c.rank = TWO;
	c.suit = SPADE;

	CARD b;
	b.rank = SIX;
	b.suit = CLUB;

	return 0;
}

