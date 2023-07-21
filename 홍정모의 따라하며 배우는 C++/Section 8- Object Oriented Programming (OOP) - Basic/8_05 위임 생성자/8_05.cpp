//위임 생성자: 생성자가 다른 생성자를 사용하는것

#include <iostream>
#include <string>

using namespace std;

/* #1 class 작성 */
class Student
{
private:
	int m_id;
	string m_name;

public:
/* #2 이름만 입력해서 instance를 만들고 싶을 경우를 위해 아래 코드(위임생성자)를 작성 
   -> 이런 방식은 비추천 */

	Student(const string& name_in)
		// :m_id(0), m_name(name_in) :: 또 다시 초기화하는 대신에 아래처럼
		// :Student(0, name_in)  /* #3 만능초기화 함수 작성으로 아래로 대체도 가능 */
	{
		init(0, name_in);
	}
/* #2 이름만 입력해서 instance를 만들고 싶을 경우를 위해 위 코드(위임생성자)를 작성 */

	Student(const int& id_in, const string& name_in)
	//	: m_id(id_in), m_name(name_in) 	/* #3 만능초기화 함수 작성으로 아래로 대체도 가능 */
	{
		init(id_in, name_in);
	}

/* #3 만능초기화 함수 작성 */
	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}

	void print()
		{
			cout << "m_id" << m_id << endl;
			cout << "m_name" << m_name << endl;
		}
};


int main()
{

	Student st1(0, "Jack Jack");
	st1.print();


/* #2 이름만 입력해서 instance를 만들고 싶을 경우를 위해 아래 코드(위임생성자)를 작성 */
	Student st2("Dash");
	st2.print();

	return 0;
}