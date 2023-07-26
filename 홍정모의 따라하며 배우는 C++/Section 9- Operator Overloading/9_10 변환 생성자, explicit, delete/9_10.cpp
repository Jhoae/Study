#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:

/* #2 delete */
	Fraction(char) = delete;


/* #1 explicit - ��ȯ ������ ���� */
	explicit Fraction(int num = 0, int den = 1)
		:m_numerator(num), m_denominator(den)
	{ assert(den != 0); }

	Fraction(const Fraction& fraction)
		:m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{}


	friend std::ostream& operator <<(std::ostream& out, const Fraction& f)
	{
		out << "\nf.m_numerator:\t" << f.m_numerator << endl;
		out << "f.m_denominator:\t" << f.m_denominator << endl;
		out << f.m_numerator << " / " << f.m_denominator << endl;

		return out;
	}
};

void doSomething(Fraction frac)
{
	cout << "doSomething�� frac:\t" << frac << endl;
}


int main()
{
	Fraction frac(7); 

/* #1 explicit */
	doSomething(frac); 
	doSomething(Fraction(7,2));
	// doSomething(8); // explicitŰ���带 ����ϸ� ERROR �߻�

/* #2 delete */
	// Fraction frac2('c'); // delete(char) Ű���带 ����ϸ� ERROR �߻�

	return 0;
}