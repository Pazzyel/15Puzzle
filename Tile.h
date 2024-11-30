#pragma once
#include "Tile.h"
#include <iostream>
#include <iomanip>

//Æå×Ó
class Tile {
public:
	Tile() = default;
	explicit Tile(int num)
		: m_num{ num } {
	}

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile) {
		if (tile.m_num)
			out << std::setw(3) << tile.m_num << ' ';
		else
			out << "    ";
		return out;
	}

	constexpr bool isEmpty() const {
		return !m_num;
	}

	constexpr int getNum() const {
		return m_num;
	}
private:
	int m_num{ 0 };//0ÔòÎª¿Õ
};