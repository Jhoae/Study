#include <iostream>
#include <string>

using namespace std;

/* #1 class�� const 
	-> member variable���� const�� �Ǵ°Ͱ� ���� ȿ���� ��Ÿ���� */
class Something
{
public:
	int m_value = 0;

/* #2 ~ �Ʒ��� ���� "copy Constructor"�� ���� �ִ� */
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


/* #2 print�Լ� - �Լ��� �����ϸ� instance�� ���簡 �ȴ�
	 -> ������ "Constructor"�� �ѹ��� �۵��ϴµ� �� ������ "Copy Constructor"  */
void print(Something st)
{
	cout << "print�� &st:\t" << &st << endl;
	cout << "print�� st.getValue():\t" << st.getValue() << endl;
}


/* #3 print�Լ��� �������� �ʵ��� ���� -> reference ��� */
void print_ref (const Something &st)
{
	cout << "print_ref�� &st:\t" << &st << endl;
	cout << "print_ref�� st.getValueConst():\t" << st.getValueConst() << endl;
}



/* #4 �Լ��� const ������ �����ε��� �ǳ�, �ȵǳ� ���� */
class Something_ov
{
public:
	string m_value = "default";

	const string& getValue() const // const reference�� return
	{ 
		cout << "const getValue()" << endl;
		return m_value; 
	}
	string& getValue()  // non-const reference�� return
	{ 
		cout << "non-const getValue()" << endl;
		return m_value; 
	}
};




int main()
{
printf("#1 class�� const\n");
/* #1 class�� const
	-> member variable���� const�� �Ǵ°Ͱ� ���� ȿ���� ��Ÿ���� */
	const Something something; // const instance ���� 
							   // -> m_value�� const�� �ȴ�

	// ERROR :: something.setValue(3);
	// ERROR :: something.getValue();
	something.getValueConst();



	printf("\n#2 print�Լ�\n");
/* #2 print�Լ� */
	Something some_p;
	some_p.setValue(3);

	cout << "&some_p:\t\t" << &some_p << endl;

	print(some_p);


// �Լ��� �Ű������� �����ϸ� ����ȴ� -> &some_p�� &st�� �ּҰ��� �ٸ���.


	printf("\n#3 print�Լ��� �������� �ʵ��� ���� -> reference ���\n");
/* #3 print�Լ��� �������� �ʰ� �������� ����ϵ��� ����ȭ ���� 
      -> reference ��� 
      -> &some_ref�� &st�� �ּҰ��� ���� */

	Something some_ref;
	some_ref.setValue(3);

	cout << "&some_ref:\t\t" << &some_ref << endl;

	print_ref(some_ref);





	printf("\n#4 �Լ��� const ������ �����ε��� �ǳ�, �ȵǳ� ����\n");
/* #4 �Լ��� const ������ �����ε��� �ǳ�, �ȵǳ� ���� */
	Something_ov something_ov;
	something_ov.getValue();	// non-const getValue()
	// -> ���� �ٲܼ� �ִ�
	printf("\nnon- const �̹Ƿ� ���� �ٲܼ� �ִ�\n");
	something_ov.getValue() = "new string";
	cout << "something_ov.m_value:\t" << something_ov.m_value << endl;

	printf("\n");
	const Something_ov something_ov2; // -> member variable���� const�� �Ǵ°Ͱ� ���� ȿ���� ��Ÿ����
	printf("\nconst �̹Ƿ� ���� �ٲܼ� ����\n");
	something_ov2.getValue();	// const getValue()
	cout << "something_ov2.m_value:\t" << something_ov2.m_value << endl;
	// ERROR :: something_ov2.getValue() = "new string";

	return 0;
}