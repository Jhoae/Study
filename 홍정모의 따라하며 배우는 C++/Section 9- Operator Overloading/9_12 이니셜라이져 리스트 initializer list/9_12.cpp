#include <iostream>
#include <cassert>
#include <initializer_list>
using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr; // 메모리 동적 할당

public:
	IntArray(unsigned length) 
		: m_length(length)
	{
		m_data = new int[length];
	}

/* #2 initializer를 입력으로 받는 생성자를 구현 
      -> initializer list를 매개변수로 받기 */ 
	IntArray(const std::initializer_list<int>& list)
		:IntArray(list.size()) // 위 생성자를 호출해 메모리를 받아온다
	{
		// 받아온 메모리에 list의 내용을 복사
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}

		// 위를 짧게하기위해 아래처럼 수정 -> ERROR
		//for (unsigned count = 0; count < list.size(); ++count)
		//	m_data[count] = list[count];   
		// ERROR -> initializer list는 []를 제공하지 않는다
	}


	~IntArray()
	{
		delete[] this->m_data;
	}

	// 출력 연산자
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

/* #1 initializer_list사용 동기 */
	int my_arr1[5] = { 1,2,3,4,5 }; // 정적 initializer_list로 값을 초기화
	int* my_arr2 = new int[5] {1, 2, 3, 4, 5}; // 동적 initializer_list로 값을 초기화

	auto il = { 10,20,30 }; // auto로 initializer_list로 값을 초기화


/* #2 initializer list를 매개변수로 받기 */
	IntArray int_array{ 1,2,3,4,5,6,7,8,9 };
	cout << "int_array:\t" << int_array << endl;
	
	return 0;
}