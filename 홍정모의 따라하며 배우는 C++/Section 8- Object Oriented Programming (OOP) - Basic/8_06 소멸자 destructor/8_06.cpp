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
	/* Constructor�� Destructor */
	Simple s1(0);
	Simple s2(1);

	// ���� 
	// Con 0
	// Con 1
	// Des 1
	// Des 0


	printf("\n");
	/* �����Ҵ��� ��� */
	Simple* s1_m = new Simple(2);
	Simple ss2(3);

	delete s1_m;

	// ���� 
	// Con 2
	// Con 3
	// Des 2
	// Des 3


/* #3 int Array�� �Ҹ��� ��� */
	class IntArray {
	private:
		int* m_arr = nullptr;
		int m_length = 0;
	

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];

		cout << "IntArray ����" << endl;
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



/* [����] �Ҹ��ڴ� instance�� �޸𸮿��� ������ �� ���ο��� �ڵ����� ȣ��˴ϴ�.
   ���� �Ҵ����� ������� ��쿡�� ������ ����� �ڵ����� �޸𸮰� �������� �ʱ�
   ������ delete���� �޸𸮸� ������ ������ �Ҹ��ڰ� ȣ��˴ϴ�.
   �Ҹ��ڸ� ���α׷��Ӱ� ���� ȣ���ϴ� ���� ��κ��� ��� �������� �ʽ��ϴ�. */


	return 0;
}