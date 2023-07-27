#pragma once

#include <iostream>

class Position2D
{
private:
	int m_x;
	int m_y;

public:
	Position2D(const int &x_input, const int& y_input)
		:m_x(x_input), m_y(y_input)
	{}

	// Todo:: overload operator

	void set(const Position2D& pos_target)
	{
		set(pos_target.m_x, pos_target.m_y); // 아래 함수를 재사용하기
		// m_x = postarget.m_x;
		// m_y = postarget.m_y;
	}

	void set(const int& x_target, const int& y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}

	friend std::ostream& operator<<(std::ostream& out, const Position2D& pos2d)
	{
		out << "( x: " << pos2d.m_x << " / " << "y: " << pos2d.m_y << " )" << std::endl;
		return out;
	}

};