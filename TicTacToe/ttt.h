#ifndef TTT_H
#define TTT_H
#include <iostream>
using namespace std;

class ttt {
public:
	ttt();
	bool game;
	bool win;
	int player;
	int square;
	int turnCounter;
	int grid[9];
	bool gridCheck[9];
	void initializeGrid(void);
	void printGrid(void);
	void playerTurn(bool);
	void gameCheck(bool);
};


#endif