#include <iostream>
#include <cassert>
using namespace std;

class MyString
{
public:
	char* m_data = nullptr; // ���ڿ��� �ּ�
	int m_length = 0;

public:
/* #1 ���ڿ� class ���� */
	MyString(const char* source = "") // ���ڿ��� �޴´�
	{
		assert(source); // �� ���ڿ����� Ȯ��

		m_length = std::strlen(source) + 1; // ���ڿ� ���� '\0'�� �߰��ϱ� ���� +1
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}
	

	/* #3 copy constructor->delete�� ����ؼ� memory�� ���� ���� 
		-> �ּҰ��� �����ϴ� ���, �޸𸮸� �ٽ� �Ҵ�޾Ƽ�(new) ���� ���� 
		- ���� ���� */
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
	
/* #6 delete�� �̿��� �������� �����ϱ� ���� (���� ���縦 �����Ҽ� ���ٸ�) 
	MyString(const MyString& source) = delete; */



/* #4 ���� �������� ��������, ���� ���� */
	MyString& operator = (const MyString & source)
	{
		/* #4-1 ���� 
		���� ���� shallow copy ��� ...
		
		this->m_data = source.m_data;
		this->m_length = source.m_length; 
		*/

		cout << "Assignment operator" << endl;


		if (this == &source) // prevent self-assignment :: hello = hello ����
			return *this;

		delete[] m_data;

		m_length = source.m_length;

		/* #4-2 ���� ���� */
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
		/* #2 �⺻(default) ���� ������ ȣ�� - ���� ���� */
		MyString copy = hello; 
		// (int*)hello.m_data�� ����
		cout << "(int*)copy.m_data:\t" << (int*)copy.m_data << endl;
		cout << "copy.getString():\t" << copy.getString() << endl;
	} 

	/* #2 ���� ���縦 �̿��� copy�� �������� ����鼭 delete[] �� ȣ���Ͽ�, 
	���� �ּҸ� ����Ű�� �ִ� hello�� ���� delete �Ǿ��� 
	-> ���� ����� �ذ� ( copy�� hello�� �ּҰ��� �޶�����. ) */
	cout << "hello.getString():\t" << hello.getString() << endl;


/* #5 */
	MyString str1 = hello; // Copy Constructor�� ȣ���
	// == MyString str1(hello);

	MyString str2;
	str2 = hello; // Assignment operator�� ȣ���

	return 0;
}