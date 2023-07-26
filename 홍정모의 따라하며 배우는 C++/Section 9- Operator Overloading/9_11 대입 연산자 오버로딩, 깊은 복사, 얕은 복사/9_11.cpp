#include <iostream>
#include <cassert>
using namespace std;

class MyString
{
public:
	char* m_data = nullptr; // 문자열의 주소
	int m_length = 0;

public:
/* #1 문자열 class 구현 */
	MyString(const char* source = "") // 문자열을 받는다
	{
		assert(source); // 빈 문자열인지 확인

		m_length = std::strlen(source) + 1; // 문자열 끝에 '\0'을 추가하기 위해 +1
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}
	

	/* #3 copy constructor->delete를 대비해서 memory를 따로 설정 
		-> 주소값을 복사하는 대신, 메모리를 다시 할당받아서(new) 값을 복사 
		- 깊은 복사 */
	MyString(const MyString& source)
	{
		cout << "Copy Constructor" << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
	} 
	
/* #6 delete를 이용해 얕은복사 방지하기 가능 (깊은 복사를 구현할수 없다면) 
	MyString(const MyString& source) = delete; */



/* #4 대입 연산자의 얕은복사, 깊은 복사 */
	MyString& operator = (const MyString & source)
	{
		/* #4-1 만약 
		얕은 복사 shallow copy 라면 ...
		
		this->m_data = source.m_data;
		this->m_length = source.m_length; 
		*/

		cout << "Assignment operator" << endl;


		if (this == &source) // prevent self-assignment :: hello = hello 방지
			return *this;

		delete[] m_data;

		m_length = source.m_length;

		/* #4-2 깊은 복사 */
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	} 
	


	~MyString()
	{
		delete[] m_data;
	} 

	char* getString() { return m_data; }
	int getLenght() { return m_length; }
};

int main()
{

/* #1 */
	MyString hello("Hello");

	cout << "(int*)hello.m_data:\t" << (int*)hello.m_data << endl;
	cout << "hello.getString():\t" << hello.getString() << endl;


	{
		/* #2 기본(default) 복사 생성자 호출 - 얕은 복사 */
		MyString copy = hello; 
		// (int*)hello.m_data와 같다
		cout << "(int*)copy.m_data:\t" << (int*)copy.m_data << endl;
		cout << "copy.getString():\t" << copy.getString() << endl;
	} 

	/* #2 얕은 복사를 이용한 copy가 스코프를 벗어나면서 delete[] 를 호출하여, 
	같은 주소를 가리키고 있던 hello의 값도 delete 되었다 
	-> 깊은 복사로 해결 ( copy와 hello의 주소값이 달라졌다. ) */
	cout << "hello.getString():\t" << hello.getString() << endl;


/* #5 */
	MyString str1 = hello; // Copy Constructor가 호출됨
	// == MyString str1(hello);

	MyString str2;
	str2 = hello; // Assignment operator가 호출됨

	return 0;
}