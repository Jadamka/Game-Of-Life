#include <iostream>

#include "map.h"

int main()
{
	makeMap();

	while (true)
	{
		system("cls");
		displayMap();
		cellularAutomata();
		std::cin.get();
	}

	return 0;
}