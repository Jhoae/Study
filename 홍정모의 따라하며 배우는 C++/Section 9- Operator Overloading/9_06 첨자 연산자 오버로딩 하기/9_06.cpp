// 첨자 연산자 []

#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10]{ 1,2,3,4,5,6,7,8,9,10 }; // 정적 메모리 할당

public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getList()
	{
		return m_list;
	}

/* #2  첨자 연산자 [] 
		- 위 3가지 함수를 대체할수 있다. */
	int& operator[](const int index)
	{

/* #4 assert를 사용하여 runtime error 방지.
      -> if문을 사용하면 performance가 느려진다 - 권장X*/
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

/* #3 const 로 instance를 만들경우 
    -> const 버전의 operator를 만들면 overloading이 된다 */
	const int& operator[](const int index) const
	{
		return m_list[index];
	}



};



int main()
{

/* #1 기본적인 set함수와 get함수를 사용 */
	IntList my_list;

	my_list.setItem(3, 1);
	cout << "my_list.getItem(3):\t\t" << my_list.getItem(3) << endl;

	my_list.getList()[3] = 77;
	cout << "my_list.getList()[3] = 77:\t" 
		<< my_list.getList()[3] << endl;




	printf("\n#2  첨자 연산자 [] - set함수와 get함수가 필요없다\n");
/* #2  첨자 연산자 [] - set함수와 get함수가 필요없다 */

	IntList my_list2;
	my_list2[3] = 10; // L-value로 사용
	cout << "my_list2[3]:\t" << my_list2[3] << endl; 

	printf("\n#3 const 로 instance를 만들경우 -> const 버전의 operator를 만들면 overloading이 된다\n");
/* #3 const 로 instance를 만들경우
	-> const 버전의 operator를 만들면 overloading이 된다 */

	const IntList my_list_c;
	// ERROR:my_list_c[3] = 10;
	cout << "my_list_c[3]:\t" << my_list_c[3] << endl;


	
/* #5 주의사항 - pointer 사용시*/
	IntList* list = new IntList;

	// Not OK :: list[3] = 10;    ( list[3]은 다른 의미 )  
	(*list)[3] = 10; // OK

	return 0;
}