#ifndef _DIRECTION_H_
#define _DIRECTION_H_

#include <iostream>
#include "Random.h"

//·½Ïò
class Direction {
public:
	enum Direct {
		up,
		down,
		left,
		right,
	};

	explicit Direction(Direct direction);
	explicit Direction(char direction);
	Direction(const Direction& direction);
	Direction(Direction&& direction) noexcept;

	Direction operator-();

	friend std::ostream& operator<<(std::ostream& out, const Direction& direction);

	constexpr Direct getDirection() const { return m_direction; }//constexpr function only can be define in header, because the compiler must know it's composition

	static Direction randomDirection();

private:
	Direct m_direction{};
};

#endif // !_DIRECTION_H_