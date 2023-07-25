#include <iostream>
using namespace std;

/* #1 ������ ������� class ������� */
class Cents
{
private:
	int m_cents;

public:

	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	
	int& getCents() { return m_cents; } 
	// ��� ���� m_cents�� ���� ������ ��ȯ�ϹǷ�, 
	//��ü�� ���� ���¸� ������ �� �ֽ��ϴ�. 

/* #4 ������ overloading�� member function���� ����
	  -> getCents���̵� ��°����ϰ� ���� 
	  -> friend Ű���� ��� */
	Cents operator +(const Cents& c2)
	{
		return Cents(this->m_cents + c2.m_cents);
	}


/* #5 member function���θ� overloading�� ������ �����ڵ� 
* =, [index], (), -> 
*/
};

void add(const Cents& c1, const Cents& c2, Cents& c_out)
{
	c_out.getCents() = c1.getCents() + c2.getCents();
}


/* #2 ��������� �ִ� ������ add function*/
Cents add_2(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

/* #3 operator +�� �̿��� add */
Cents operator +(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}




int main()
{
/* #1 ������ ������� class ������� */
	Cents cents1(6);
	Cents cents2(8);

	Cents sum;
	add(cents1, cents2, sum);

	cout << "sum.getCents():\t" << sum.getCents() << endl;
	
	//  ?:  ::  sizeof  .  .*



/* #2 ��������� �ִ� ������ add function*/
	cout << "add_2(cents1, cents2).getCents():\t" 
		<< add_2(cents1, cents2).getCents() << endl;




/* #3 operator +�� �̿��� add */
	cout << "(cents1 + cents2 + Cents(6)).getCents():\t" 
		<< (cents1 + cents2 + Cents(6)).getCents() << endl;



/* #4 friend Ű���� ���*/
	cout << "(cents1 + cents2 + Cents(6) + Cents(100)):\t"
		<< (cents1 + cents2 + Cents(6) + Cents(100)).getCents() << endl;

	return 0;
}