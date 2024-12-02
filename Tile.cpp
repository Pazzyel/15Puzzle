#include "Tile.h"
#include <iostream>
#include <iomanip>

Tile::Tile() = default;
Tile::Tile(int num)
	: m_num{ num } {
}

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
	if (tile.m_num)
		out << std::setw(3) << tile.m_num << ' ';
	else
		out << "    ";
	return out;
}
