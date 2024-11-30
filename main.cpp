#include "Board.h"
#include <cstdlib>

namespace UserInput {
	Direction shiftCharToDirection(char char_direction) {
		return Direction{ char_direction };
	}

	char getInput() {
		char input{};
		while (true) {
			std::cin >> input;
			if (!std::cin || (input != 'w' && input != 'a' && input != 's' && input != 'd' && input != 'q')) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			break;
		}
		return input;
	}

	bool adjustBoard(char input,Board& board) {
		if (input == 'q') {
			std::cout << "\n\nBye!\n\n";
			return false;//用来跳过打印棋盘
		}
		//std::cout << "Valid command: " << shiftCharToDirection(input) << '\n';
		Direction direction{ input };
		return board.moveTile(direction);
	}



	void getAndPrint(Board& board) {
		std::cout << "This is the state you want to restore to.\n";
		std::cout << board << "\n\n\n";

		for (int i{ 0 }; i < 250; ++i) {//打乱
			board.moveTile(Direction::randomDirection());
		}
		std::cout << "The game board has been disrupted.\nUse \"w a s d\" to control.\n";
		std::cout << board;

		bool game_result{ false };
		char input{};
		while (input != 'q') {
			std::cout << "Enter a command: ";
			input = getInput();
			if (!adjustBoard(input, board))
				continue;
			else
				std::cout << board;
			if (board.checkRegular()) {
				game_result = true;
				break;
			}
		}

		if (game_result)
			std::cout << "\n\nYou won!\n\n";
	}
}

int main() {
	Board board{};
	UserInput::getAndPrint(board);
	system("pause");

	return 0;
}
