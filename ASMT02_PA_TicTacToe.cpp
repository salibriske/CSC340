//
//ASMT02_PA_TicTacToe.cpp
//Tommy Tran
//Partner: Brandon Chen
//Due Date 10/18/18
//CSC340 Assignment 2A
//
#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {
	//
	//    PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			break;
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			break;
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}

/*
check if the outcome for player 1 or player 2 is the winner with a line of three
 */
bool isWon(char won, char board[][3]) {
	//Vertical and horizontal
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((board[i][0] == won && board[i][1] == won && board[i][2] == won) ||
				(board[0][j] == won && board[1][j] == won && board[2][j] == won)) {
				return true;
			}
		}
	}
	//diagonal 
	if ((board[0][0] == won && board[1][1] == won && board[2][2] == won) ||
		(board[0][2] == won && board[1][1] == won && board[2][0] == won)) {
		return true;
	}
	return false;
}


/*
 checks the outcome is a draw with all cells are filled.
 */
bool isDraw(char board[][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
			//checks the board to stop if there are no more moves. 
			if (board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}
/*
 Displays current board before player input.
 */
void displayBoard(char board[][3]) {
	cout << "\n-------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "|";
		for (int j = 0; j < 3; j++) {
			//board being blank at the beginning
			//position of the move being X, O, or blank
			switch (board[i][j]) {
			case 'X': cout << " X " << "|";
				break;
			case 'O': cout << " O " << "|";
				break;
			default: cout << "   " << "|";
				break;
			}
		}
		cout << endl;
		cout << "-------------\n";
	}
}
/*
 User input on the position and check it is valid or occupied
 */
void makeAMove(char board[][3], char move) {
	int row, col;
	while (true) {   //Allows player to make mistake and maintain turn
		//Prompt user input location
		cout << "Enter a row (0, 1, 2) for Player " << move << ": ";
		cin >> row;
		cout << "Enter a colum (0, 1, 2) for Player " << move << ": ";
		cin >> col;

		//Checks if input is out of bounds
		if (row > 2 || row < 0 || col > 2 || col < 0) {
			cout << "Invalid move; cell out of bounds!\n";
		}else if (board[row][col] != 'X' && board[row][col] != 'O') {
			board[row][col] = move;
			break;  //Ends player turn
		} else {
			cout << "This cell is currently occupied. Try a different cell\n";
		}
	}
}