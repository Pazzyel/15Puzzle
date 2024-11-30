#pragma once
#include "Direction.h"
#include <iostream>
#include "Random.h"

//方向
class Direction {
public:
	enum Direct {
		up,
		down,
		left,
		right,
	};

	explicit Direction(Direct direction)
		: m_direction{ direction } {
	}
	explicit Direction(char direction) {
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
	Direction(const Direction& direction)
		: Direction{ direction.m_direction } {
	}
	Direction(Direction&& direction) noexcept
		: Direction{ direction.m_direction } {
	}

	Direction operator-() {
		switch (m_direction) {
		case up:    return Direction{ down };
		case down:  return Direction{ up };
		case left:  return Direction{ right };
		case right: return Direction{ left };
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Direction& direction) {
		switch (direction.m_direction) {
		case up:
			out << "up";
			break;
		case down:
			out << "down";
			break;
		case left:
			out << "left";
			break;
		case right:
			out << "right";
			break;
		}
		return out;
	}

	constexpr Direct getDirection() const { return m_direction; }

	static Direction randomDirection() {//与对象无关，设置为static
		return Direction{ static_cast<Direct>(Random::get(static_cast<int>(up),static_cast<int>(right))) };
	}

private:
	Direct m_direction{};
};