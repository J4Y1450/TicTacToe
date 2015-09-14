#include "ttt.h"

ttt::ttt(){
	game = true;
	initializeGrid();
	printGrid();
	while(game){
		playerTurn(false);
		printGrid();
		gameCheck(false);
		if(game){
			playerTurn(true);
			printGrid();
			gameCheck(true);
		}
	}
	
}

void ttt::initializeGrid(){
	for(int i = 0; i < 9; i++){
		grid[i] = 0;
		gridCheck[i] = false;
	}
	turnCounter = 0;
	win = false;
}

void ttt::printGrid(){
	for(int i = 0; i < 9; i++){
		if(i == 3){
			cout << "	1|2|3" << endl << "-+-+-	-+-+-" << endl;
		}
		if(i == 6){
			cout << "	4|5|6" << endl << "-+-+-	-+-+-" << endl;
		}

		switch(grid[i]){
		case 1:
			cout << "X";
			break;
		case 2:
			cout << "O";
			break;
		default:
			cout << "-";
		}

		if(i != 2 && i != 5 && i != 8){
			cout << "|";
		} 
	}
	cout << "	7|8|9";
	cout << endl << endl;
}

void ttt::playerTurn(bool player2){
	if(game){	
		player = 1;
		if(player2){
			player = 2;
		}

		do{
			cout << "Player " << player << ": ";
			cin >> square;
			cout << endl;
			if(square < 1 || square > 9){
				cout << "That space doesn't exist!\n" << endl;
			}
			if(gridCheck[square-1] == true){
				cout << "That space is already taken!\n" << endl;
			}
		} while(gridCheck[square-1] == true || square < 1 || square > 9);

		if(player == 1){
			grid[square-1] = 1;
		}
		if(player == 2){
			grid[square-1] = 2;
		}

		gridCheck[square-1] = true;
	}
}

void ttt::gameCheck(bool player2){
	int player = 1;
	if(player2){
		player = 2;
	}
	for(int i = 0; i < 3; i++){
		if(grid[0+i] == player && grid[3+i] == player && grid[6+i] == player){
			win = true;
		}
		if(grid[0+(i*3)] == player && grid[1+(i*3)] == player && grid[2+(i*3)] == player){
			win = true;
		}
	}
	if(grid[0] == player && grid[4] == player && grid[8] == player){
		win = true;
	}
	if(grid[2] == player && grid[4] == player && grid[6] == player){
		win = true;
	}
	
	if(win){
		cout << "Player " << player << " wins!" << endl;
		game = false;
	}
	if(turnCounter > 7 && win == false){
		cout << "Tie game! Nobody wins." << endl;
		game = false;
	}
	turnCounter++;
}