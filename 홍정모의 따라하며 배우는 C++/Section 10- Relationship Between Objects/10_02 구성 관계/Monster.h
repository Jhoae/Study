#pragma once

#include <string>
#include "Position2D.h"

/* #1 �Ϲ����� class ��� */
class Monster
{
private:
	std::string m_name; // char * data, unsigned length �� ��� ���
	int m_x; // ��ġ
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



/* #2 Position2D class�� �����Ͽ� m_x�� m_y ó���ϱ�  */

class Monster_posi
{
private:
	std::string m_name; // char * data, unsigned length �� ��� ���
	
/* #2 */
	// Monster_posi�� sub class�� Position2D�� �ۼ���.
	// -> int m_x, m_y�� �����ϰ� ó��. 
	// => ���� Ŭ����(Monster_posi)�� ���(ex- set�Լ� )�� �и��� �� �ִ�
	Position2D m_location; 
	// -> ��������. m_location�� Monster_posi�� �Ϻ��̴�.
	// m_location�� �׻� m_name�� �Բ� ������ �ʿ�� ����.


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