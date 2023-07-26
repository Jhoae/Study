#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:

	// �⺻ ������	
	Fraction(int num = 0, int den = 1)
		:m_numerator(num), m_denominator(den)
	{
		cout << "Default Constructor called" << endl;
		assert(den != 0);
	}

/* #1 ���� ������ copy Constructor */
	Fraction(const Fraction &fraction) 
		:m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy Constructor called" << endl;
	}


	friend std::ostream& operator <<(std::ostream& out, const Fraction& f)
	{
		out << "\nf.m_numerator:\t" << f.m_numerator << endl;
		out << "f.m_denominator:\t" << f.m_denominator<< endl;
		out << f.m_numerator << " / " << f.m_denominator << endl;

		return out;
	}


};

/* #4 */
Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << "&temp:\t\t" << &temp << endl;
	return temp;
}


int main()
{
	Fraction frac(3, 5); // �⺻ ������ ȣ��
	

	printf("\n#1 ���� ������ copy Constructor\n");
/* #1 ���� ������ copy Constructor */
	Fraction fr_copy(frac); // ���� ������ ȣ��

	cout << "frac:\t" << frac << endl;
	cout << "fr_copy:\t" << fr_copy << endl;


	printf("\n#2 copy initialization -> ��� ����� �ٸ����� copy constructor�� �Ȱ��� ȣ��ȴ�\n");
/* #2 copy initialization 
      -> ��� ����� �ٸ����� copy constructor�� �Ȱ��� ȣ��ȴ� */
	Fraction fr_copy_init = frac;



	printf("\n#3 Copy Constructor�� ȣ����� �ʴ´� -> Compiler�� ���ʿ��ϴٰ� �����ϸ� �����Ѵ�\n");
/* #3 Copy Constructor�� ȣ����� �ʴ´�
      -> Compiler�� ���ʿ��ϴٰ� �����ϸ� �����Ѵ� */
	Fraction fr_copy_2(Fraction(3, 10)); 




	printf("\n#4 return���ִ� �Լ�\n");
/* #4 return���ִ� �Լ� 
      ->Copy Constructor�� ȣ����� �ʴ´�  
	  -> &result�� &temp�� �ּҰ��� ���� */
	Fraction result = doSomething();
	cout << "&result:\t" << &result << endl;
	cout << "result:\t" << result << endl;

	return 0;
}