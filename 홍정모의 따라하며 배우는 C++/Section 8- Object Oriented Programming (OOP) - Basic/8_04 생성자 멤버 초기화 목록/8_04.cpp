// �������� ��� �ʱ�ȭ
// Member Initializer List

#include <iostream>

using namespace std;


int main()
{
/* #2 ��� �ȿ� �ٸ� class�� ����� �� ��� */
	class B
	{
	private:
		int m_b;

	public:
		B(const int& m_b_in)
			: m_b(m_b_in)
		{}
};

/* #1 */
	class Something
	{
	private:
		int m_i;
		double m_d;
		char m_c;
		int m_arr[5];
		B m_b; /* #2 ��� �ȿ� �ٸ� class�� ����� �� ��� */

	public:
		Something()
			// Initializer List () �Ǵ� {} ���
			: m_i{ 1 },
			m_d{ 3.14 },
			m_c{ 'a' },
			m_arr{ 5,4,3,2,1 },
			m_b{ m_i - 1 }
		{
			/* m_i = 1;
			m_d = 3.14;
			m_c = 'a'; */
		}

		void print()
		{
			cout << "m_i: " << m_i << endl;
			cout << "m_d: " << m_d << endl;
			cout << "m_c: " << m_c << endl;
			for (auto& e : m_arr)
				cout << "m_arr[]" << e << " ";
			cout << endl;
		}
	};

	Something som;
	som.print();



	printf("\n#3_twice\n");
/* #3 �ʱ�ȭ�� 2�������� �ϸ�?? 
      -> �Ѵ� ����������, ���ÿ� �Ѵٸ� �����ڰ� �켱 */
	class Something_twice
	{
	private:
		int m_i = 100;
		double m_d = 100.0;
		char m_c = 'F';
		int m_arr[5] = { 100,200,300,400,500 };
		B m_b = { 1024 }; 

	public:
		Something_twice() // ������
			// Initializer List () �Ǵ� {} ���
			: m_i{ 1 },
			m_d{ 3.14 },
			m_c{ 'a' },
			m_arr{ 5,4,3,2,1 },
			m_b{ m_i - 1 }
		{}

		void print()
		{
			cout << "twice.m_i: " << m_i << endl;
			cout << "twice.m_d: " << m_d << endl;
			cout << "twice.m_c: " << m_c << endl;
			for (auto& e : m_arr)
				cout << "m_arr[]: " << e << " ";
			cout << endl;
		}
	};

	Something_twice som_twi;
	som_twi.print();


	printf("\n3times\n");
// �ʱ�ȭ�� 3���ϸ� 
// -> �̶��� ���� Initializer List ���� �ʱ�ȭ�� ���ְ�, 
//    ���Ŀ� �ٽ� �������� ���� �������� �ȴ�.

	class Something_3times
	{
	private:
		int m_i = 100;
		double m_d = 100.0;
		char m_c = 'F';
		int m_arr[5] = { 100,200,300,400,500 };
		B m_b = { 1024 };

	public:
		Something_3times()
			// Initializer List () �Ǵ� {} ���
			: m_i{ 1 },
			m_d{ 3.14 },
			m_c{ 'a' },
			m_arr{ 5,4,3,2,1 },
			m_b{ m_i - 1 }
		{
			m_i *= 3;
			m_d *= 3.0;
			m_c += 3; // 'a' + 3 = 'd'
		}

		void print()
		{
			cout << "3times.m_i: " << m_i << endl;
			cout << "3times.m_d: " << m_d << endl;
			cout << "3times.m_c: " << m_c << endl;
			for (auto& e : m_arr)
				cout << "m_arr[]: " << e << " ";
			cout << endl;
		}
	};

	Something_3times som_3t;
	som_3t.print();

	return 0;
}
