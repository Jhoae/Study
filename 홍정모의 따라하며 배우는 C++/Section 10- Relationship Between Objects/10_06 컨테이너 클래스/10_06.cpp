#include <iostream>
#include <vector>
#include <array>

using namespace std;

class IntArray
{
private:
	int m_length = 0;
	int* m_data = nullptr;

public:
	// Constructors
	// ��Ҹ� �迭�� ���� �ʱ�ȭ�ϴ� ������
	IntArray(const initializer_list<int>& values)
		:m_length(values.size()), m_data(new int[values.size()])
	{
		int i = 0;
		for (const int& value : values)
		{
			m_data[i] = value;
			i++;
		}
	}

	// Destructors
	~IntArray()
	{
		delete[] m_data;
	}
	
	// reset(): ��� ��Ҹ� 0���� �ʱ�ȭ
	void reset()
	{
		for (int i = 0; i < m_length; ++i)
		{
			m_data[i] = 0;
		}
	}
	
	// resize(): �迭 ũ�⸦ ����
	void resize(int new_length)
	{
		int* temp_data = new int[new_length];

		// ���� ������ ���� (���� �κ�)
		int elements_to_copy = (m_length < new_length) ? m_length : new_length;
		for (int i = 0; i < elements_to_copy; ++i)
		{
			temp_data[i] = m_data[i];
		}

		// ���� �޸� ����
		delete[] m_data;

		// ���ο� �迭�� ������Ʈ
		m_data = temp_data;
		m_length = new_length;
	}


	// insertBefore: �־��� �ε����� ���ο� ��� ����
	void insertBefore(const int& value, const int& index)
	{
		if (index < 0 || index > m_length)
		{
			return; // ��ȿ���� ���� �ε���
		}

		int* temp_data = new int[m_length + 1];

		for (int before = 0; before < index; ++before)
		{
			temp_data[before] = m_data[before];
		}

		temp_data[index] = value;

		for (int after = index; after < m_length; ++after)
		{
			temp_data[after + 1] = m_data[after];
		}

		delete[] m_data;
		m_data = temp_data;
		m_length++;
	}
	
	// remove: �־��� �ε����� ��� ����
	void remove(const int& index)
	{
		if (index < 0 || index >= m_length)
		{
			return; // ��ȿ���� ���� �ε���
		}

		int* temp_data = new int[m_length - 1];

		for (int before = 0; before < index; ++before)
		{
			temp_data[before] = m_data[before];
		}

		for (int after = index + 1; after < m_length; ++after)
		{
			temp_data[after - 1] = m_data[after];
		}

		delete[] m_data;
		m_data = temp_data;
		m_length--;
	}
	
	// push_back: �迭 ���� ��� �߰�
	void push_back(const int& value)
	{
		int* temp_data = new int[m_length + 1];

		for (int i = 0; i < m_length; ++i)
		{
			temp_data[i] = m_data[i];
		}

		temp_data[m_length] = value;

		delete[] m_data;
		m_data = temp_data;
		m_length++;
	}

	// ��� ������ �����ε�
	friend ostream& operator <<(ostream& out, const IntArray& arr)
	{
		out << "[";
		for (int i = 0; i < arr.m_length; ++i)
		{
			out << arr.m_data[i];
			if (i != arr.m_length - 1)
				out << ", ";
		}
		out << "]";
		return out;
	}
};


int main()
{
	IntArray my_arr{ 1, 3, 5, 7, 9 };
	my_arr.insertBefore(10, 1);		// 1, 10, 3, 5, 7, 9
	cout << "insertBefore(10, 1) ����:\t" << my_arr << endl;

	my_arr.remove(3);				// 1, 10, 3, 7, 9
	cout << "remove(3) ����:\t\t\t" << my_arr << endl;


	my_arr.push_back(13);			// 1, 10, 3, 7, 9, 13
	cout << "push_back(13) ����:\t\t" << my_arr << endl;



/* #1 vector�� array���� Containers */
	std::vector<int> int_vec;      // int�� vector�� ������� (���� �Ҵ�)
	std::array<int, 10> int_arr;   // int�� array�� �������




	return 0;
}