
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
/* struct */
	struct Date_strc
	{
		int m_month;
		int m_day;
		int m_year;
	};

	Date_strc today_strc1{ 7, 21,2023 };
	// �Ǵ� 
	Date_strc today_strc2;
	today_strc2.m_month = 7;
	today_strc2.m_day = 21;
	today_strc2.m_year = 2023;


/* class - public */
	class Date_class_pub
	{
	public: // ���� ������. default���� private.
		int m_month;
		int m_day;
		int m_year;
	};

	Date_class_pub today_pub;
	today_pub.m_month = 7;
	today_pub.m_day = 21;
	today_pub.m_year = 2023;



/* class - ��� - private����,, ���� �Լ� - public���� �ۼ� */
	class Date_class_priv
	{
	private: // ���� ������. default���� private.
		int m_month;
		int m_day;
		int m_year;

	public:
		void setDate(const int& month_input, const int& day_input, const int& year_input)
		{
			m_month = month_input;
			m_day = day_input;
			m_year = year_input;
		}

		void setMonth(const int& month_input)
		{
			m_month = month_input;
		} // setDay, setYear ... - setters


/* get ���� �Լ� (get Access Function) �ۼ� - getters*/
		const int& getDay() 
		{
			return m_day;
		}

/* ����� private�����ϴ���, 
   ���� class�� �ٸ� instance(�Ʒ� ��� �Ű������� ���� original)�� ����ִ� ����� ���� �����ϴ� */
		void copyFrom(Date_class_priv& original)
		{
			m_month = original.m_month;
			m_day = original.m_day;
			m_year = original.m_year;
		}
	};

	Date_class_priv today_priv;
	// Error: Date_class_priv today_priv2{ 7,21,2023 };  
	today_priv.setDate(7, 21, 2023);
	today_priv.setMonth(8);

	cout << "today_priv.getDay(): " << today_priv.getDay() << endl;

	Date_class_priv copy;
	copy.copyFrom(today_priv);

	// �̶� m_month�� m_month2�� �ٲ۴ٸ� ???

/* ĸ��ȭ�� �Ҷ� getter, setter�� �����ϴ� ������ ���� 
   - ������� �ٲ���� ���, ������ �ڵ尡 �ſ� �������µ�, 
	 �̸� �����Ͽ� class �ȿ����� �����ص� �����ϰ� ���� �� �ִ� */
	class Date_class_problem
	{
	public: // ���� ������. default���� private.
		int m_month;
		int m_day;
		int m_year;
	};

	Date_class_problem copy_p;
	copy_p.m_day = 123;
	copy_p.m_month = 45;

// -> �ذ�
	class Date_class_solution
	{
	private: 
		int m_month2;
		int m_day;
		int m_year;

	public:
		void setDate(const int& month_input, const int& day_input, const int& year_input)
		{
			m_month2 = month_input;
			m_day = day_input;
			m_year = year_input;
		}

		void setMonth(const int& month_input)
		{
			m_month2 = month_input;
		} // setDay, setYear ... - setters

		const int& getDay()
		{
			return m_day;
		}

		void copyFrom(Date_class_solution& original)
		{
			m_month2 = original.m_month2;
			m_day = original.m_day;
			m_year = original.m_year;
		}
	};

	return 0;
}