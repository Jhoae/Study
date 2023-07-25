// ÷�� ������ []

#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10]{ 1,2,3,4,5,6,7,8,9,10 }; // ���� �޸� �Ҵ�

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

/* #2  ÷�� ������ [] 
		- �� 3���� �Լ��� ��ü�Ҽ� �ִ�. */
	int& operator[](const int index)
	{

/* #4 assert�� ����Ͽ� runtime error ����.
      -> if���� ����ϸ� performance�� �������� - ����X*/
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

/* #3 const �� instance�� ������ 
    -> const ������ operator�� ����� overloading�� �ȴ� */
	const int& operator[](const int index) const
	{
		return m_list[index];
	}



};



int main()
{

/* #1 �⺻���� set�Լ��� get�Լ��� ��� */
	IntList my_list;

	my_list.setItem(3, 1);
	cout << "my_list.getItem(3):\t\t" << my_list.getItem(3) << endl;

	my_list.getList()[3] = 77;
	cout << "my_list.getList()[3] = 77:\t" 
		<< my_list.getList()[3] << endl;




	printf("\n#2  ÷�� ������ [] - set�Լ��� get�Լ��� �ʿ����\n");
/* #2  ÷�� ������ [] - set�Լ��� get�Լ��� �ʿ���� */

	IntList my_list2;
	my_list2[3] = 10; // L-value�� ���
	cout << "my_list2[3]:\t" << my_list2[3] << endl; 

	printf("\n#3 const �� instance�� ������ -> const ������ operator�� ����� overloading�� �ȴ�\n");
/* #3 const �� instance�� ������
	-> const ������ operator�� ����� overloading�� �ȴ� */

	const IntList my_list_c;
	// ERROR:my_list_c[3] = 10;
	cout << "my_list_c[3]:\t" << my_list_c[3] << endl;


	
/* #5 ���ǻ��� - pointer ����*/
	IntList* list = new IntList;

	// Not OK :: list[3] = 10;    ( list[3]�� �ٸ� �ǹ� )  
	(*list)[3] = 10; // OK

	return 0;
}