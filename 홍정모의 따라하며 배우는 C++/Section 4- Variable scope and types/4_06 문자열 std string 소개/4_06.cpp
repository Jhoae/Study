#include <iostream>
#include <string>


using namespace std;

int main()
{
	const char my_strings[] = "Hello, World"; // �⺻ �ڷ����� char. ���ڿ��ϰ�� [] �߰�
	const string my_hello = "Hello, World"; // string :: ����� ���� �ڷ���.

	string my_ID = "123";

	cout << "Hello, World" << endl; // char[13] == ���� 12���� + '\0'(null character)
	cout << my_hello << endl;
	cout << my_strings << endl;



	/*				*/

	cout << "Your id ? : \n";
	int id;
	cin >> id; // ���� x

	// buffer ����
	//std::cin.ignore(32767, '\n'); // == \n������ 32767���� �������ϸ� ����������. 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	cout << "Your name ? : \n";
	string name;
	// cin >> name; // ���� x
	std::getline(std::cin, name); // line������ �����Ƿ� ���⵵ ����

	cout << "Your age ? : \n";
	string age;
	// cin >> age; // ���� x
	std::getline(std::cin, age);



	cout << id << " " << name << " " << age << endl;


	printf("\n");
	/*	String ���ϱ� ���� (append)			*/
	string l("Hello, ");
	string m("World ");
	string n = l + m; // append

	n += "I'm good";

	cout << n << endl;
	cout << n.length() << endl; // ���ڿ� ���� ���� (null character ����)

	return 0;
}