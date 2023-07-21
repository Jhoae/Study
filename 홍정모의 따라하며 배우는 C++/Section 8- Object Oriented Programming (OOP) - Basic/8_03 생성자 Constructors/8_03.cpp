#include <iostream>

using namespace std;

int main()
{

	class Fraction
	{
	private:
		int m_default; 
		int m_numerator;   // ���� 
		int m_denominator; // �и�

	public: 

/* ������ Constructor->����� ���ÿ� ����ȴ�. 
         - default ������ : �⺻���� ������ ������ */
		Fraction(const int& num_input = 1, const int& den_input = 3) // �⺻�� �Ҵ� ��� 1
		{
			m_default = 1; // �⺻�� �Ҵ� ��� 2
			m_numerator = num_input;
			m_denominator = den_input;

			cout << "Fraction() Constructor" << endl;
		}

		void print()
		{
			cout << "m_numerator / m_denominator: " 
				<< m_numerator << " / " << m_denominator << endl;
		}
	};


/* �����ڸ� �����ϸ� �⺻ �����ڰ� �������� �ʴ´�. 
   ��� �Ű����� ���𿡼� �⺻���� ������ �� �ִ�. */

	Fraction one_thirds;
	one_thirds.print();


/* copy initialization - ����X */
	Fraction one_forth = Fraction{ 1,4 }; // ���� �ȴ�
	one_forth.print();

/* (), {} ���� ������ 
   - {}�� ������� public�� ��� ������ ���� ��� ���� 
     & �����ڸ� �̿��ϴ��� Ÿ�Կ� ���� �����ϴ� */
	Fraction one_fifth1{ 1,3 };
	Fraction one_fifth2( 1,3 );

	/* Ÿ�Կ� �����ϴ�
	   Error:  Fraction one_fifth1{ 1.0, 3 };
	      OK:  Fraction one_fifth2(1.0, 3); */


		  
	printf("\n");
/* class�� ������ ���� ���*/

	class Second
	{
	public:
		Second()
		{
			cout << "Class Second" << endl;
		}
	};
	class First
	{
	private:
		Second sec;

	public:
		First()
		{
			cout << "Class First" << endl;
		}
	};

	First fir;
	// Debug�� "Class Second"�� "Class First" ���� ���� ��µ�
	// -> second�� first�� ����� ����ֱ� ������, ����� ���� �ʱ�ȭ�����
	//    first�� �۾� �����ϱ� ������

	return 0;
}