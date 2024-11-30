#pragma once

//表示棋盘的大小
static constexpr int s_size{ 4 };

constexpr int g_consoleLines{ 25 };

#include "Board.h"
#include <iostream>
#include <vector>
#include "Tile.h"
#include "Direction.h"
#include "Point.h"

//棋盘
class Board {
public:
	Board()
		:m_chess_board{ std::vector{ Tile{ 1 } ,Tile{ 2 } ,Tile{ 3 } ,Tile{ 4 } }    
		               ,std::vector{ Tile{ 5 } ,Tile{ 6 } ,Tile{ 7 } ,Tile{ 8 } }
					   ,std::vector{ Tile{ 9 } ,Tile{ 10 } ,Tile{ 11 } ,Tile{ 12 } } 
		               ,std::vector{ Tile{ 13 } ,Tile{ 14 } ,Tile{ 15 } ,Tile{ 0 }} } {//以未打乱状态初始化
	}


	friend std::ostream& operator<<(std::ostream& out, const Board& board) {
		for (std::size_t i{ 0 }; i < s_size; ++i) {
			for (std::size_t j{ 0 }; j < s_size; ++j)
				out << board.m_chess_board[i][j];
			out << '\n';
		}
		return out;
	}

	Point findEmpty() {
		std::size_t x{ 0 };
		std::size_t y{ 0 };
		for (; x < s_size; ++x) {
			for (; y < s_size; ++y)
				if (m_chess_board[y][x].isEmpty())
					break;
			if (y == s_size)
				y = 0;
			if (m_chess_board[y][x].isEmpty())
				break;
		}
		return Point{ x,y };
	}

	//成功移动返回true
	bool moveTile(const Direction& direction) {
		Point empty{ findEmpty() };
		Point adjacent_point{ 0,0 };

		if (empty.getAdjacentPoint(direction.getDirection()) != std::nullopt)
			adjacent_point = *empty.getAdjacentPoint(direction.getDirection());
		else
			return false;

		std::swap(m_chess_board[empty.getPointY()][empty.getPointX()], m_chess_board[adjacent_point.getPointY()][adjacent_point.getPointX()]);//vector是[y,x]表示
		return true;
	}

	bool checkRegular() {
		if (m_chess_board[0][0].getNum() == 1 && m_chess_board[0][1].getNum() == 2 && m_chess_board[0][2].getNum() == 3 && m_chess_board[0][3].getNum() == 4 &&
			m_chess_board[1][0].getNum() == 5 && m_chess_board[1][1].getNum() == 6 && m_chess_board[1][2].getNum() == 7 && m_chess_board[1][3].getNum() == 8 &&
			m_chess_board[2][0].getNum() == 9 && m_chess_board[2][1].getNum() == 10 && m_chess_board[2][2].getNum() == 11 && m_chess_board[2][3].getNum() == 12 &&
			m_chess_board[3][0].getNum() == 13 && m_chess_board[3][1].getNum() == 14 && m_chess_board[3][2].getNum() == 15 && m_chess_board[3][3].getNum() == 0)
			return true;
		else
			return false;
	}

private:
	std::vector<std::vector<Tile>> m_chess_board{};
};