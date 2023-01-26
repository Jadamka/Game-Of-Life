#ifndef MAP_H
#define MAP_H

#define MAP_WIDTH 40
#define MAP_HEIGHT 20

void makeMap();
int near(int x, int y);
void cellularAutomata();
void displayMap();
void copyToMap(bool x[MAP_HEIGHT][MAP_WIDTH], bool y[MAP_HEIGHT][MAP_WIDTH]);

#endif
