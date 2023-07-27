#include "Monster.h"

using namespace std;


int main()
{
	
/* #1 일반적인 class 사용 */
	Monster mon1("Devil", 0, 0);

	// while (true) // game loop
	{
		// event
		mon1.moveTo(1, 3);
		cout << "mon1:\t" << mon1 << endl;
	}


	printf("\n#2 Position2D class를 도입하여 m_x와 m_y 처리하기\n");
/* #2 Position2D class를 도입하여 m_x와 m_y 처리하기  */
	Monster_posi mon2("angel", Position2D(2,5));
	// mon2.m_location;
	cout << "mon2:\t" << endl;

	Monster_posi mon3("Parsival", Position2D(4, 1));
	// mon3.m_location;

	{
		// event
		mon2.moveTo(Position2D(1, 1));
		cout << "이동후 mon2:\t" << mon2 << endl;
	}


	return 0;
}