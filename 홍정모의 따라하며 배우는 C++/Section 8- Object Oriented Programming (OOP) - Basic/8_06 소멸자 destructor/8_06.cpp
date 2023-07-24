#include <iostream>
using namespace std;

class Simple
{
public:
	int m_id;

	Simple(const int &id_input)
		: m_id(id_input)
	{
		cout << "Constructor m_id: " << m_id << endl;
	}

	~Simple()
	{
		cout << "Destructor m_id: " << m_id << endl;
	}

};

int main()
{
	/* Constructor와 Destructor */
	Simple s1(0);
	Simple s2(1);

	// 순서 
	// Con 0
	// Con 1
	// Des 1
	// Des 0


	printf("\n");
	/* 동적할당일 경우 */
	Simple* s1_m = new Simple(2);
	Simple ss2(3);

	delete s1_m;

	// 순서 
	// Con 2
	// Con 3
	// Des 2
	// Des 3


/* #3 int Array의 소멸자 사용 */
	class IntArray {
	private:
		int* m_arr = nullptr;
		int m_length = 0;
	

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "IntArray 생성" << endl;
	}

	~IntArray()
	{
		if(m_arr !=nullptr)
			delete[] m_arr;
	}

	int size() { return m_length; }
	
};

	while (true)
	{
		IntArray my_int_arr(10000);

	}



/* [보충] 소멸자는 instance가 메모리에서 해제될 때 내부에서 자동으로 호출됩니다.
   동적 할당으로 만들어진 경우에는 영역을 벗어나도 자동으로 메모리가 해제되지 않기
   때문에 delete으로 메모리를 해제할 때에만 소멸자가 호출됩니다.
   소멸자를 프로그래머가 직접 호출하는 것은 대부분의 경우 권장하지 않습니다. */


	return 0;
}