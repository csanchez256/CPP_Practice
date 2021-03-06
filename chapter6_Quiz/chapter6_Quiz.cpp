#include "stdafx.h"
#include <iostream>
#include <string>


enum ITEMS {
	HEALTH_POTIONS = 2,
	TORCHES = 5,
	ARROWS = 10
};


struct STUDENT {
	std::string NAME;
	int GRADE;
};	
void countTotalItems(ITEMS *array, int arraySize) {
	int i;
	int totalItems = 0;
	for (i = 0; i < arraySize; ++i) {
		totalItems += array[i];
	}	
	std::cout << "total items is " << totalItems << std::endl;
}

void roster() {
	std::cout << "How many student names do you want to enter? " << std::endl;
	int numStudents;
	std::cin >> numStudents;
	//std::cin.ignore();

	std::string *sArray = new std::string[numStudents];

	STUDENT student;

	std::cout << "Enter name of student and grade " << std::endl;
	int i;
	std::string name;
	for (i = 0; i < numStudents; ++i) {
		
	getline(std::cin, name);
	std::cout << "name is " << name << std::endl;
	std::cin.ignore();
	sArray[i] = name;	
	}

	for (int j = 0; j < numStudents; ++j) {
		std::cout << sArray[j] << std::endl;
	}
}	

void swap(int x, int y) {
	std::cout << "x is = " << x << " y = " << y << std::endl;
	/*int temp;
	temp = x;
	x = y;
	y = temp;*/

	const int &ref = x;
	 x = y;
	 y = ref;

	std::cout << "x is = " << x << " y = " << y << std::endl;
}

int main()
{
	ITEMS array[3] = { HEALTH_POTIONS, TORCHES, ARROWS };
	int arraySize = sizeof(array) / sizeof(array[0]);

	//countTotalItems(array, arraySize);
	//roster();
	swap(1, 2);
    return 0;
}

