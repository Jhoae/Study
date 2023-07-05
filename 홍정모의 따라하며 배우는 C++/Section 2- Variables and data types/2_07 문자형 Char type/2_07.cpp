#include <iostream>

int main()
{
	using namespace std;

	char c1(65);
	char c2('A');	// ''�� �ٸ��� ���ڿ��� ��Ÿ������ "":: "Hello, World", std::string

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;
	// A A 65 65
	printf("\n");

	// c style Casting
	cout << (char)65 << endl; // A
	cout << (int)'A' << endl; // 65
	printf("\n");

	// c++ style Casting
	cout << char(65) << endl; // A
	cout << int('A') << endl; // 65
	printf("\n");

	cout << static_cast<char>(65) << endl; // A
	cout << static_cast<int>('A') << endl; // 65
	printf("\n");

	char ch(97);
	cout << ch << endl;						// a
	cout << static_cast<int>(ch) << endl;	// 97
	cout << ch << endl;						// a
	printf("\n");

	// cin
	char ch1(65);
	cin >> ch1;
	cout << ch1 << " " << static_cast<int>(ch1) << endl;
	printf("\n");

	// limits
	cout << sizeof(char) << endl;								// 1
	cout << (int)std::numeric_limits<char>::max() << endl;		// 127
	cout << (int)std::numeric_limits<char>::lowest() << endl;	// -128
	printf("\n");

	cout << sizeof(unsigned char) << endl;								// 1
	cout << (int)std::numeric_limits<unsigned char>::max() << endl;		// 255
	cout << (int)std::numeric_limits<unsigned char>::lowest() << endl;	// 0
	printf("\n");

	// \n  : �ٹٲ�
	//endl : �ٹٲް� ���ÿ� buffer�� �ִ� ��� ������ ����϶�� �ǹ�
	cout << int('\n') << endl;		// 10
	cout << "This is first line \nsecond line\n";
	cout << "This is first line" << endl;
	cout << "second line" << endl;
	printf("\n");

	// std::flush ----  �ٹٲ��� �������� 
	//					buffer�� �ִ� ��� ������ ����϶�� �ǹ�
	cout << "This is first line" << flush;
	cout << "second line" << endl;


	// \t: tab
	cout << int('\t') << endl;
	cout << "This is first line \tsecond line" << endl;

	// "�� ����ϰ� �ʹٸ�...
	cout << "\"" << endl;

	// \a: �����
	cout << "\a" << endl;


	// �ٸ� type��
	wchar_t wc1;
	char16_t wc2;
	char32_t wc3;

	return 0;
}