#include "Point.h"
#include <optional>
#include "Direction.h"

constexpr int s_size{ 4 };

Point::Point(std::size_t x, std::size_t y)
	: m_x{ x }
	, m_y{ y } {
}
Point::Point(const Point& point)
	:Point{ point.m_x,point.m_y } {
}
Point::Point(Point&& point) noexcept
	:Point{ point.m_x,point.m_y } {
}
Point& Point::operator=(Point&& point) noexcept {//赋值修改自己返回*this！
	if (&point == this)
		return *this;

	m_x = point.m_x;
	m_y = point.m_y;
	return *this;
}

std::optional<Point> Point::getAdjacentPoint(Direction::Direct direction) {
	switch (direction) {
	case Direction::up:
		if (static_cast<int>(m_y) - 1 < 0)
			return std::nullopt;
		return Point{ m_x,m_y - 1 };
	case Direction::down:
		if (static_cast<int>(m_y) + 1 >= s_size)
			return std::nullopt;
		return Point{ m_x,m_y + 1 };
	case Direction::left:
		if (static_cast<int>(m_x) - 1 < 0)
			return std::nullopt;
		return Point{ m_x - 1,m_y };
	case Direction::right:
		if (static_cast<int>(m_x) + 1 >= s_size)
			return std::nullopt;
		return Point{ m_x + 1,m_y };
	default:
		return std::nullopt;
	}
}

bool operator==(const Point& point1, const Point& point2) {
	return point1.m_x == point2.m_x && point1.m_y == point2.m_y;
}
bool operator!=(const Point& point1, const Point& point2) {
	return !(point1 == point2);
}