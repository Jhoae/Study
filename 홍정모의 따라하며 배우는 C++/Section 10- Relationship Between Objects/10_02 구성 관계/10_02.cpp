#include "Monster.h"

using namespace std;


int main()
{
	
/* #1 �Ϲ����� class ��� */
	Monster mon1("Devil", 0, 0);

	// while (true) // game loop
	{
		// event
		mon1.moveTo(1, 3);
		cout << "mon1:\t" << mon1 << endl;
	}


	printf("\n#2 Position2D class�� �����Ͽ� m_x�� m_y ó���ϱ�\n");
/* #2 Position2D class�� �����Ͽ� m_x�� m_y ó���ϱ�  */
	Monster_posi mon2("angel", Position2D(2,5));
	// mon2.m_location;
	cout << "mon2:\t" << endl;

	Monster_posi mon3("Parsival", Position2D(4, 1));
	// mon3.m_location;

	{
		// event
		mon2.moveTo(Position2D(1, 1));
		cout << "�̵��� mon2:\t" << mon2 << endl;
	}


	return 0;
}