#include <iostream>
#include <string>

using namespace std;

/* #1 class와 const 
	-> member variable들이 const가 되는것과 같은 효과가 나타난다 */
class Something
{
public:
	int m_value = 0;

/* #2 ~ 아래와 같은 "copy Constructor"가 숨어 있다 */
	Something(const Something& st_input)
	{
		cout << "st_input.m_value:\t" << st_input.m_value << endl;
		m_value = st_input.m_value;
		cout << "Copy Constructor" << endl;
	}
/* ~ #2 */

	Something()
	{
		cout << "Constructor" << endl;
	}

	void setValue(int value) { m_value = value; }
	int getValue() { return m_value; }

	int getValueConst() const { return m_value; }
};


/* #2 print함수 - 함수로 전달하면 instance가 복사가 된다
	 -> 하지만 "Constructor"는 한번만 작동하는데 그 이유는 "Copy Constructor"  */
void print(Something st)
{
	cout << "print의 &st:\t" << &st << endl;
	cout << "print의 st.getValue():\t" << st.getValue() << endl;
}


/* #3 print함수가 복사하지 않도록 개선 -> reference 사용 */
void print_ref (const Something &st)
{
	cout << "print_ref의 &st:\t" << &st << endl;
	cout << "print_ref의 st.getValueConst():\t" << st.getValueConst() << endl;
}



/* #4 함수의 const 유무로 오버로딩이 되냐, 안되냐 결정 */
class Something_ov
{
public:
	string m_value = "default";

	const string& getValue() const // const reference를 return
	{ 
		cout << "const getValue()" << endl;
		return m_value; 
	}
	string& getValue()  // non-const reference를 return
	{ 
		cout << "non-const getValue()" << endl;
		return m_value; 
	}
};




int main()
{
printf("#1 class와 const\n");
/* #1 class와 const
	-> member variable들이 const가 되는것과 같은 효과가 나타난다 */
	const Something something; // const instance 생성 
							   // -> m_value가 const가 된다

	// ERROR :: something.setValue(3);
	// ERROR :: something.getValue();
	something.getValueConst();



	printf("\n#2 print함수\n");
/* #2 print함수 */
	Something some_p;
	some_p.setValue(3);

	cout << "&some_p:\t\t" << &some_p << endl;

	print(some_p);


// 함수의 매개변수로 전달하면 복사된다 -> &some_p와 &st의 주소값이 다르다.


	printf("\n#3 print함수가 복사하지 않도록 개선 -> reference 사용\n");
/* #3 print함수가 복사하지 않고 같은것을 사용하도록 최적화 개선 
      -> reference 사용 
      -> &some_ref와 &st의 주소값이 같다 */

	Something some_ref;
	some_ref.setValue(3);

	cout << "&some_ref:\t\t" << &some_ref << endl;

	print_ref(some_ref);





	printf("\n#4 함수의 const 유무로 오버로딩이 되냐, 안되냐 결정\n");
/* #4 함수의 const 유무로 오버로딩이 되냐, 안되냐 결정 */
	Something_ov something_ov;
	something_ov.getValue();	// non-const getValue()
	// -> 값을 바꿀수 있다
	printf("\nnon- const 이므로 값을 바꿀수 있다\n");
	something_ov.getValue() = "new string";
	cout << "something_ov.m_value:\t" << something_ov.m_value << endl;

	printf("\n");
	const Something_ov something_ov2; // -> member variable들이 const가 되는것과 같은 효과가 나타난다
	printf("\nconst 이므로 값을 바꿀수 없다\n");
	something_ov2.getValue();	// const getValue()
	cout << "something_ov2.m_value:\t" << something_ov2.m_value << endl;
	// ERROR :: something_ov2.getValue() = "new string";

	return 0;
}