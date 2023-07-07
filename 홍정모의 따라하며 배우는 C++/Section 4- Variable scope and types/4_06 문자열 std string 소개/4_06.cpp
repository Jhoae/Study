#include <iostream>
#include <string>


using namespace std;

int main()
{
	const char my_strings[] = "Hello, World"; // 기본 자료형인 char. 문자열일경우 [] 추가
	const string my_hello = "Hello, World"; // string :: 사용자 정의 자료형.

	string my_ID = "123";

	cout << "Hello, World" << endl; // char[13] == 글자 12글자 + '\0'(null character)
	cout << my_hello << endl;
	cout << my_strings << endl;



	/*				*/

	cout << "Your id ? : \n";
	int id;
	cin >> id; // 띄어쓰기 x

	// buffer 비우기
	//std::cin.ignore(32767, '\n'); // == \n전까지 32767개의 문자이하를 날려버려라. 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	cout << "Your name ? : \n";
	string name;
	// cin >> name; // 띄어쓰기 x
	std::getline(std::cin, name); // line단위로 읽으므로 띄어쓰기도 가능

	cout << "Your age ? : \n";
	string age;
	// cin >> age; // 띄어쓰기 x
	std::getline(std::cin, age);



	cout << id << " " << name << " " << age << endl;


	printf("\n");
	/*	String 더하기 연산 (append)			*/
	string l("Hello, ");
	string m("World ");
	string n = l + m; // append

	n += "I'm good";

	cout << n << endl;
	cout << n.length() << endl; // 문자열 길이 측정 (null character 제외)

	return 0;
}