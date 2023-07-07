#include <iostream>
#include <typeinfo>
#include <string>


/* 열거형을 사용하지 않는다면 ...
	int computeDamange(int weapon_id)
	{
		if (weapon_id == 0)// sword
			return 1;

		if (weapon_id == 1)// hammer
			return 2;

		// ....
	}
*/

/*	열거형 사용 예시		*/
enum Color // 사용자 정의 자료형 user-defined data types
{
	// 내부적으로 정수로 저장된다.
	COLOR_BLACK,		// 0
	COLOR_RED,			// 1
	COLOR_BLUE,			// 2
	COLOR_GREEN,		// 3
	COLOR_SKYBLUE,		// 4
	// ...
};

enum Feeling
{
	// COLOR_BLACK // Error: 겹치는 이름 불가능
	HAPPY = -3,		// 숫자 custom도 가능
	JOY = 5,		// 5로 설정한다면 ...
	TIRED,			// 6
	SAD,			// 7
	TT = 5,			// 만약 같게 설정한다면... -> 문제가 생길 수 있음. 권장X
	// ...
};

int main()
{
	using namespace std;

	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color apple{ COLOR_RED };
	
	
	Color my_color = COLOR_BLACK;
	Color my_color2 = COLOR_RED;

	cout << my_color << " " << COLOR_BLACK << endl;
	cout << my_color2 << " " << COLOR_RED << endl;


	if (JOY == TT)
		cout << "equal" << endl;

	printf("\n");
	/* 	내부적으로 정수로 저장되지만 100% 호환되지는 않는다 	*/
	int color_id = COLOR_RED;
	cout << color_id << endl;	 // 1
	
	// Color int_color = color_id;	 // Error
	Color int_color = static_cast<Color>(1); // casting은 가능
	
	// cin >> int_color; // Error
	// 위 방식을 우회하면
	int in_number;
	cin >> in_number;
	if (in_number == 0) int_color == COLOR_BLACK;
	// ...

	// 또는
	if (in_number == static_cast<Color>(0))
		int_color == static_cast<Color>(0);


	/*	String으로 입력받기 - 비추		 */
	string str_input;
	std::getline(cin, str_input);

	if (str_input == "COLOR_BLACK")
		int_color == static_cast<Color>(0);

	return 0;
}