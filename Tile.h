#ifndef _TILE_H_
#define _TILE_H_

#include <iostream>
//Tile
class Tile {
public:
	Tile();
	explicit Tile(int num);

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);

	constexpr bool isEmpty() const {//constexpr function only can be define in header, because the compiler must know it's composition
		return !m_num;
	}

	constexpr int getNum() const {
		return m_num;
	}

private:
	int m_num{ 0 };//0 represents null
}; 

#endif // !_TILE_H_