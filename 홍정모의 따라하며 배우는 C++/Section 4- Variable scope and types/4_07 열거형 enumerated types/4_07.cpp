#include <iostream>
#include <typeinfo>
#include <string>


/* �������� ������� �ʴ´ٸ� ...
	int computeDamange(int weapon_id)
	{
		if (weapon_id == 0)// sword
			return 1;

		if (weapon_id == 1)// hammer
			return 2;

		// ....
	}
*/

/*	������ ��� ����		*/
enum Color // ����� ���� �ڷ��� user-defined data types
{
	// ���������� ������ ����ȴ�.
	COLOR_BLACK,		// 0
	COLOR_RED,			// 1
	COLOR_BLUE,			// 2
	COLOR_GREEN,		// 3
	COLOR_SKYBLUE,		// 4
	// ...
};

enum Feeling
{
	// COLOR_BLACK // Error: ��ġ�� �̸� �Ұ���
	HAPPY = -3,		// ���� custom�� ����
	JOY = 5,		// 5�� �����Ѵٸ� ...
	TIRED,			// 6
	SAD,			// 7
	TT = 5,			// ���� ���� �����Ѵٸ�... -> ������ ���� �� ����. ����X
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
	/* 	���������� ������ ��������� 100% ȣȯ������ �ʴ´� 	*/
	int color_id = COLOR_RED;
	cout << color_id << endl;	 // 1
	
	// Color int_color = color_id;	 // Error
	Color int_color = static_cast<Color>(1); // casting�� ����
	
	// cin >> int_color; // Error
	// �� ����� ��ȸ�ϸ�
	int in_number;
	cin >> in_number;
	if (in_number == 0) int_color == COLOR_BLACK;
	// ...

	// �Ǵ�
	if (in_number == static_cast<Color>(0))
		int_color == static_cast<Color>(0);


	/*	String���� �Է¹ޱ� - ����		 */
	string str_input;
	std::getline(cin, str_input);

	if (str_input == "COLOR_BLACK")
		int_color == static_cast<Color>(0);

	return 0;
}