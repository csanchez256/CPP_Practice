#include "stdafx.h"
#include <iostream>

void swap(int x, int y) {
	std::cout << "x = " << x << " y = " << y << std::endl;

	int temp = x;
	x = y;
	y = temp;

	std::cout << "x = " << x << " y = " << y << std::endl;
}

