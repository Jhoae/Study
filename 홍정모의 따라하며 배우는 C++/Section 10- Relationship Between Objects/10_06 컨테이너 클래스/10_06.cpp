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
	// 요소를 배열로 직접 초기화하는 생성자
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
	
	// reset(): 모든 요소를 0으로 초기화
	void reset()
	{
		for (int i = 0; i < m_length; ++i)
		{
			m_data[i] = 0;
		}
	}
	
	// resize(): 배열 크기를 변경
	void resize(int new_length)
	{
		int* temp_data = new int[new_length];

		// 기존 데이터 복사 (공통 부분)
		int elements_to_copy = (m_length < new_length) ? m_length : new_length;
		for (int i = 0; i < elements_to_copy; ++i)
		{
			temp_data[i] = m_data[i];
		}

		// 기존 메모리 정리
		delete[] m_data;

		// 새로운 배열로 업데이트
		m_data = temp_data;
		m_length = new_length;
	}


	// insertBefore: 주어진 인덱스에 새로운 요소 삽입
	void insertBefore(const int& value, const int& index)
	{
		if (index < 0 || index > m_length)
		{
			return; // 유효하지 않은 인덱스
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
	
	// remove: 주어진 인덱스의 요소 제거
	void remove(const int& index)
	{
		if (index < 0 || index >= m_length)
		{
			return; // 유효하지 않은 인덱스
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
	
	// push_back: 배열 끝에 요소 추가
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

	// 출력 연산자 오버로딩
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
	cout << "insertBefore(10, 1) 이후:\t" << my_arr << endl;

	my_arr.remove(3);				// 1, 10, 3, 7, 9
	cout << "remove(3) 이후:\t\t\t" << my_arr << endl;


	my_arr.push_back(13);			// 1, 10, 3, 7, 9, 13
	cout << "push_back(13) 이후:\t\t" << my_arr << endl;



/* #1 vector나 array같은 Containers */
	std::vector<int> int_vec;      // int가 vector에 담겨있음 (동적 할당)
	std::array<int, 10> int_arr;   // int가 array에 담겨있음




	return 0;
}