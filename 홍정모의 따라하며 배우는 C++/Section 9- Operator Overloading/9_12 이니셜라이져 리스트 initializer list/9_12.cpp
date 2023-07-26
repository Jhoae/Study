#include <iostream>
#include <cassert>
#include <initializer_list>
using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr; // �޸� ���� �Ҵ�

public:
	IntArray(unsigned length) 
		: m_length(length)
	{
		m_data = new int[length];
	}

/* #2 initializer�� �Է����� �޴� �����ڸ� ���� 
      -> initializer list�� �Ű������� �ޱ� */ 
	IntArray(const std::initializer_list<int>& list)
		:IntArray(list.size()) // �� �����ڸ� ȣ���� �޸𸮸� �޾ƿ´�
	{
		// �޾ƿ� �޸𸮿� list�� ������ ����
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}

		// ���� ª���ϱ����� �Ʒ�ó�� ���� -> ERROR
		//for (unsigned count = 0; count < list.size(); ++count)
		//	m_data[count] = list[count];   
		// ERROR -> initializer list�� []�� �������� �ʴ´�
	}


	~IntArray()
	{
		delete[] this->m_data;
	}

	// ��� ������
	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << "arr.m_data[i]: " << " / ";
		out << endl;
		return out;
	}
};

int main()
{

/* #1 initializer_list��� ���� */
	int my_arr1[5] = { 1,2,3,4,5 }; // ���� initializer_list�� ���� �ʱ�ȭ
	int* my_arr2 = new int[5] {1, 2, 3, 4, 5}; // ���� initializer_list�� ���� �ʱ�ȭ

	auto il = { 10,20,30 }; // auto�� initializer_list�� ���� �ʱ�ȭ


/* #2 initializer list�� �Ű������� �ޱ� */
	IntArray int_array{ 1,2,3,4,5,6,7,8,9 };
	cout << "int_array:\t" << int_array << endl;
	
	return 0;
}