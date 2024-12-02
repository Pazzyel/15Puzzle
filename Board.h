#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <vector>
#include "Tile.h"
#include "Direction.h"
#include "Point.h"

//棋盘
class Board {
public:
	Board();

	friend std::ostream& operator<<(std::ostream& out, const Board& board);

	Point findEmpty();

	//成功移动返回true
	bool moveTile(const Direction& direction);

	bool checkRegular();

private:
	std::vector<std::vector<Tile>> m_chess_board{};
};

#endif // !_BOARD_H_