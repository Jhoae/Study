#include <iostream>

using namespace std;

template<class T, int size>
class StaticArray
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[] (int index)
	{
		return m_array[index];
	}

	void print()
	{
		for (int count = 0; count < size; ++count)
			cout << (*this)[count] << ' ';
		cout << endl;
	}
};

/*
#3 member �� �ű��
template <typename T, int size>
void print(StaticArray<T, size>& array)
{
	for (int count = 0; count < size; ++count)
		cout << array[count] << ' ';
	cout << endl;
}
*/



/* #2 size�� �״�� �ΰ�, T�� char type�� ���ؼ� ���ø�ȭ */
template <int size>
void print(StaticArray<char, size>& array)
{
	for (int count = 0; count < size; ++count)
		cout << array[count];
	cout << endl;
}



/* #4 member�� specialization �ϴ� ��� -->> class ��� �ޱ� */
template<class T_2, int size>
class StaticArray_BASE
{
private:
	T_2 m_array[size];

public:
	T_2* getArray() { return m_array; }

	T_2& operator[] (int index)
	{
		return m_array[index];
	}

	void print()
	{
		for (int count = 0; count < size; ++count)
			cout << m_array[count] << ' ';
		cout << endl;
	}
};

template<class T_2, int size>
class StaticArray_2 : public StaticArray_BASE<T_2, size>
{
};

template<int size>
class StaticArray_2<char,size> : public StaticArray_BASE<char, size>
{
public:
	void print()
	{
		for (int count = 0; count < size; ++count)
			cout << (*this)[count];
		cout << endl;
	}
};
/* */


int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	// print(int4); #3
	int4.print();



/* #2 size�� �״�� �ΰ�, T�� char type�� ���ؼ� ���ø�ȭ */
	StaticArray<char, 14> char14;
	char14[0] = 'H';
	char14[1] = 'e';
	// ...
	strcpy_s(char14.getArray(), 14, "Hello, World");
	// strcpy_s((char*)&char14[0], 14 * sizeof(char), "Hello, World");

	// print(char14); #3
	char14.print(); 




	printf("\n#4 member�� specialization �ϴ� ��� -->> ��� �ޱ�\n");
/* #4 member�� specialization �ϴ� ��� -->> ��� �ޱ� */
	StaticArray_2<int, 4> int4_2;

	int4_2[0] = 5;
	int4_2[1] = 6;
	int4_2[2] = 7;
	int4_2[3] = 8;

	int4_2.print();


	StaticArray_2<char, 14> char14_2;
	char14_2[0] = 'H';
	char14_2[1] = 'e';
	// ...
	strcpy_s(char14_2.getArray(), 14, "World, Hello");
	
	char14_2.print();

	return 0;
}