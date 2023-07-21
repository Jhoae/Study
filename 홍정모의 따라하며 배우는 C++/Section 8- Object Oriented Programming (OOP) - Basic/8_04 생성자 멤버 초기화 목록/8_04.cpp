// 생성자의 멤버 초기화
// Member Initializer List

#include <iostream>

using namespace std;


int main()
{
/* #2 멤버 안에 다른 class의 멤버가 들어갈 경우 */
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
		B m_b; /* #2 멤버 안에 다른 class의 멤버가 들어갈 경우 */

	public:
		Something()
			// Initializer List () 또는 {} 사용
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
/* #3 초기화를 2군데에서 하면?? 
      -> 둘다 가능하지만, 동시에 한다면 생성자가 우선 */
	class Something_twice
	{
	private:
		int m_i = 100;
		double m_d = 100.0;
		char m_c = 'F';
		int m_arr[5] = { 100,200,300,400,500 };
		B m_b = { 1024 }; 

	public:
		Something_twice() // 생성자
			// Initializer List () 또는 {} 사용
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
// 초기화를 3번하면 
// -> 이때는 먼저 Initializer List 에서 초기화를 해주고, 
//    이후에 다시 대입해준 값이 최종값이 된다.

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
			// Initializer List () 또는 {} 사용
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
