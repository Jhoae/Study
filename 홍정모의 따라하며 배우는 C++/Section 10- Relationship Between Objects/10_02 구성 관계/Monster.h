#pragma once

#include <string>
#include "Position2D.h"

/* #1 일반적인 class 사용 */
class Monster
{
private:
	std::string m_name; // char * data, unsigned length 를 묶어서 사용
	int m_x; // 위치
	int m_y;

public:
	Monster(const std::string name_input, const int &x_input, const int& y_input)
		:m_name(name_input), m_x(x_input), m_y(y_input)
	{}

	void moveTo(const int& x_target, const int& y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}

	friend std::ostream& operator<<(std::ostream& out, const Monster& monster)
	{
		out << monster.m_name << " " << "(x: " << monster.m_x << " / " << "y: " << monster.m_y << " )" << std::endl;
		return out;
	}
};



/* #2 Position2D class를 도입하여 m_x와 m_y 처리하기  */

class Monster_posi
{
private:
	std::string m_name; // char * data, unsigned length 를 묶어서 사용
	
/* #2 */
	// Monster_posi의 sub class인 Position2D를 작성함.
	// -> int m_x, m_y를 간단하게 처리. 
	// => 상위 클래스(Monster_posi)와 기능(ex- set함수 )을 분리할 수 있다
	Position2D m_location; 
	// -> 구성관계. m_location이 Monster_posi의 일부이다.
	// m_location이 항상 m_name과 함께 등장할 필요는 없다.


public:
	Monster_posi(const std::string name_input, const Position2D& pos_in)
		:m_name(name_input), m_location(pos_in)
	{}

	void moveTo(const Position2D& pos_target)
	{
		m_location.set(pos_target);
	}

	friend std::ostream& operator<<(std::ostream& out, const Monster_posi& monster)
	{
		out << monster.m_name << " " << monster.m_location << std::endl;
		return out;
	}
};