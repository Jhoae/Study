#include <iostream>

using namespace std;

int main()
{
	printf("#1\n");
	/* #1 */
	class Simple
	{
	private:
		int m_id;

	public:
		Simple(int id)
		{
			setID(id);

			/*
			   this로도 호출가능
			   this->setID(id);
			   this->m_id;
			*/

			// this == instance의 주소
			cout << "this:\t" << this << endl;
		}

		void setID(int id) { m_id = id; }
		int getID() { return m_id; }
	};

	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);

	cout << "&s1:\t" << &s1 << endl;
	cout << "&s2:\t" << &s2 << endl;

	// 개념상 Simple::setID(&s1, 2); == s1.setID(2);
	// 개념상 Simple::setID(&s2, 4); == s2.setID(4);




	printf("\n#2\n");
	/* #2 연쇄 호출 chaining member functions */
	class Calc
	{
	private:
		int m_value;

	public:
		Calc(int init_value)
			:m_value(init_value)
		{}

		void add(int value) { m_value += value; }
		void sub(int value) { m_value -= value; }
		void mult(int value) { m_value *= value; }

	// 자기 자신의 reference를 return해줄수있다
		Calc& add_ref(int value) { m_value += value; return *this; }
		Calc& sub_ref(int value) { m_value -= value; return *this; }
		Calc& mult_ref(int value) { m_value *= value; return *this; }


		void print()
		{
			cout << "m_value:\t" << m_value << endl;
		}
	};

	Calc cal(10);
	cal.add(10);
	cal.sub(1);
	cal.mult(2);
	cal.print();

	/* #2 연쇄 호출 chaining member functions*/ 

	Calc cal_ref(10);
	cal_ref.add_ref(10).sub_ref(1).mult_ref(2).print();
	/* == 같은 구현
	* Calc cal_ref(10);
	* Calc &temp1 = cal_ref.add(10);
	* Calc &temp2 = &temp1.sub(1);
	* Calc &temp3 = temp2.mult(2);
	* temp3.print();
	* == 
	* Calc(10).add(10).sub(1).mult(2).print();
	*/

	return 0;
}