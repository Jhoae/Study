
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
	// 또는 
	Date_strc today_strc2;
	today_strc2.m_month = 7;
	today_strc2.m_day = 21;
	today_strc2.m_year = 2023;


/* class - public */
	class Date_class_pub
	{
	public: // 접근 지정자. default값은 private.
		int m_month;
		int m_day;
		int m_year;
	};

	Date_class_pub today_pub;
	today_pub.m_month = 7;
	today_pub.m_day = 21;
	today_pub.m_year = 2023;



/* class - 멤버 - private으로,, 접근 함수 - public으로 작성 */
	class Date_class_priv
	{
	private: // 접근 지정자. default값은 private.
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


/* get 접근 함수 (get Access Function) 작성 - getters*/
		const int& getDay() 
		{
			return m_day;
		}

/* 멤버를 private선언하더라도, 
   같은 class의 다른 instance(아래 경우 매개변수로 받은 original)에 들어있는 멤버는 접근 가능하다 */
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

	// 이때 m_month를 m_month2로 바꾼다면 ???

/* 캡슐화를 할때 getter, setter를 구현하는 유용한 이유 
   - 멤버명을 바꿔야할 경우, 수정할 코드가 매우 많아지는데, 
	 이를 방지하여 class 안에서만 수정해도 가능하게 만들 수 있다 */
	class Date_class_problem
	{
	public: // 접근 지정자. default값은 private.
		int m_month;
		int m_day;
		int m_year;
	};

	Date_class_problem copy_p;
	copy_p.m_day = 123;
	copy_p.m_month = 45;

// -> 해결
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