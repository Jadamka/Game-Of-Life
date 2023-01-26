#include <iostream>

#include "map.h"

bool map[MAP_HEIGHT][MAP_WIDTH];
bool nmap[MAP_HEIGHT][MAP_WIDTH];
bool alive = true;

void makeMap()
{
	for (int h = 0; h < MAP_HEIGHT; h++)
	{
		for (int w = 0; w < MAP_WIDTH; w++)
		{
			map[h][w] = !alive;
		}
	}

	map[10][20] = alive;
	map[10][21] = alive;
	map[11][21] = alive;
	map[9][22] = alive;

	copyToMap(map, nmap);
}

int near(int x, int y)
{
	int count = 0;

	for (int h = y - 1; h < 2 + y; h++)
	{
		for (int w = x - 1; w < 2 + x; w++)
		{
			if (!(w == x && h == y))
				count += (int)map[h][w];
		}
	}

	return count;
}

void cellularAutomata()
{
	for (int h = 1; h < MAP_HEIGHT - 1; h++)
	{
		for (int w = 1; w < MAP_WIDTH - 1; w++)
		{
			int count = near(w, h);

			if (map[h][w] == alive && count <= 1) nmap[h][w] = !alive;
			if (map[h][w] == alive && count >= 4) nmap[h][w] = !alive;
			if (map[h][w] == !alive && count == 3) nmap[h][w] = alive;
		}
	}

	copyToMap(nmap, map);
}

void displayMap()
{
	for (int h = 0; h < MAP_HEIGHT; h++)
	{
		for (int w = 0; w < MAP_WIDTH; w++)
		{
			if (nmap[h][w])
				std::cout << '#';
			else
				std::cout << '-';
		}
		std::cout << '\n';
	}
}

void copyToMap(bool x[MAP_HEIGHT][MAP_WIDTH], bool y[MAP_HEIGHT][MAP_WIDTH])
{
	for (int h = 0; h < MAP_HEIGHT; h++)
	{
		for (int w = 0; w < MAP_WIDTH; w++)
		{
			y[h][w] = x[h][w];
		}
	}
}