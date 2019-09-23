#include <iostream>

char board[9] = {};

//очитска окна консоли
void clearscreen() {
	for (int i = 0; i < 100; i++) {
		std::cout << std::endl;
	}
}

//очистка доски
void clearboard() {
	for (int i = 0; i < 9; i++) {
		board[i] = '-';
	}
}

bool check_end(char player) {
	int winers[][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7},
	{2,5,8}, {0,4,8}, {2,4,6} };
	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 3; j++) {
			if (board[winers[i][j]] == player)
				count++;
		}
		if (count == 3) {
			return true;
		}
	}
	return false;
}

//вывод доски, в которой будут отражаться крестики и нолики
void print_board(std::string indentation) {
	std::cout << " Game Board " << std::endl;
	std::cout << indentation << "-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "- \n";
	std::cout << indentation<< "-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "- \n";
	std::cout << indentation << "-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "- \n";
}

//доп доска
int game_board() {
	std::cout << "\n    Menu    \n";
	std::cout << "-7-|-8-|-9-" << std::endl;
	std::cout << "-4-|-5-|-6-" << std::endl;
	std::cout << "-1-|-2-|-3-" << std::endl;
	std::cout << "\n";
	print_board("");
	std::cout << "\n Input number ";
	int num;
	std::cin >> num;
	while (num > 9 || num < 1 || board[num - 1] != '-') {
		std::cout << "Input number from 1 to 9\n";
		std::cin >> num;
	}
	return num;
}

//выявление победителя
char game() {
	int turn = 1;
	while (!check_end('X') && !check_end('0')) {
		clearscreen();
		int num = game_board();
		std::cout << " Result  \n";
		if (turn % 2 == 1) {
			board[num - 1] = 'X';
			if (check_end('X')) {
				std::cout << "CONGRADULATION, Player 1!\n";
				return 'X';
			}
		}
		else {
			board[num - 1] = '0';
			if (check_end('0')) {
				std::cout << "CONGRADULATION, Player 2!\n";
				return '0';
			}
		}
				turn++;
				if (turn == 10) {
					std::cout << " Draw \n";
					return 'D';
				}
			}
		}

//вывод
		int main() {
			std::cout << " Hello \n\n";
			std::string reply = "y";
			int x_wins = 0, o_wins = 0, ties = 0;
			while (reply == "y") {
				clearboard();
				char winner = game();
				print_board("\t ");
				switch (winner) {
				case 'X':
					x_wins++;
					break;
				case '0':
					o_wins++;
					break;
				case 'D':
					ties++;
					break;
				}
				std::cout << "\n\t* Stat *\n Player 1: " << x_wins << ", Player 2: " << o_wins << ", Draws : " << ties << "\n\n";
				std::cout << "\n Play again? (y/n): ";
				std::cin >> reply;
				while (reply != "y" && reply != "n") {
					std::cout << " Please, input y or n (y/n):";
					std::cin >> reply;
				}
			}
			return 0;
		}