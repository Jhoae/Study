#include <iostream>

int main()
{
	using namespace std;

	char c1(65);
	char c2('A');	// ''와 다르게 문자열을 나타낼때는 "":: "Hello, World", std::string

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

	// \n  : 줄바꿈
	//endl : 줄바꿈과 동시에 buffer에 있는 모든 내용을 출력하라는 의미
	cout << int('\n') << endl;		// 10
	cout << "This is first line \nsecond line\n";
	cout << "This is first line" << endl;
	cout << "second line" << endl;
	printf("\n");

	// std::flush ----  줄바꿈을 하지말고 
	//					buffer에 있는 모든 내용을 출력하라는 의미
	cout << "This is first line" << flush;
	cout << "second line" << endl;


	// \t: tab
	cout << int('\t') << endl;
	cout << "This is first line \tsecond line" << endl;

	// "를 출력하고 싶다면...
	cout << "\"" << endl;

	// \a: 경고음
	cout << "\a" << endl;


	// 다른 type들
	wchar_t wc1;
	char16_t wc2;
	char32_t wc3;

	return 0;
}