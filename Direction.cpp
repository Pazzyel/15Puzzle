#include "Direction.h"
#include <iostream>
#include "Random.h"

Direction::Direction(Direct direction)
	: m_direction{ direction } {
}
Direction::Direction(char direction) {
	switch (direction) {
	case 'w':
		m_direction = up;
		break;
	case 's':
		m_direction = down;
		break;
	case 'a':
		m_direction = left;
		break;
	case 'd':
		m_direction = right;
		break;
	}
}
Direction::Direction(const Direction& direction)
	: Direction{ direction.m_direction } {
}
Direction::Direction(Direction&& direction) noexcept
	: Direction{ direction.m_direction } {
}

Direction Direction::operator-() {
	switch (m_direction) {
	case up:    return Direction{ down };
	case down:  return Direction{ up };
	case left:  return Direction{ right };
	case right: return Direction{ left };
	}
}

std::ostream& operator<<(std::ostream& out, const Direction& direction) {
	switch (direction.m_direction) {
	case Direction::up:
		out << "up";
		break;
	case Direction::down:
		out << "down";
		break;
	case Direction::left:
		out << "left";
		break;
	case Direction::right:
		out << "right";
		break;
	}
	return out;
}

Direction Direction::randomDirection() {//与对象无关，设置为static
	return Direction{ static_cast<Direct>(Random::get(static_cast<int>(up),static_cast<int>(right))) };
}