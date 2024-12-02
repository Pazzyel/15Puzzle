#ifndef _POINT_H_
#define _POINT_H_

#include <optional>
#include "Direction.h"

//∆Â≈ÃŒª÷√
class Point {
public:
	Point(std::size_t x, std::size_t y);
	Point(const Point& point);
	Point(Point&& point) noexcept;
	Point& operator=(Point&& point) noexcept;

	std::optional<Point> getAdjacentPoint(Direction::Direct direction);

	constexpr std::size_t getPointX() const { return m_x; }//constexpr function only can be define in header, because the compiler must know it's composition
	constexpr std::size_t getPointY() const { return m_y; }

	friend bool operator==(const Point& point1, const Point& point2);

private:
	std::size_t m_x;
	std::size_t m_y;
};

#endif // !_POINT_H_
