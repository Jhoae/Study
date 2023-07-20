/* # �����Ҵ� �޸𸮸� ���� �����ϴ� �ͺ���, std::vector�� ����ϴ°��� �ξ� ���ϴ� */

#include <iostream>
#include <vector>

using namespace std;


/* vector�� Stackó�� ����ϴ� ��� */
void printStack(const std::vector<int>& stack)
{
	for (auto& e : stack)
		cout << "Stack[" << &e << "]: " << e << ", ";
	cout << endl;
}

int main()
{
	// int *v_ptr = new int[3] {1, 2, 3}; �� ����ϴ�
	std::vector<int> v{ 1,2,3 };


	
/* 	size�� capacity(�뷮) 
  - �ڵ� ���ο��� �뷮��ŭ �޸𸮸� ������ ������, 
    size�� ���߿��� ��� ����� �Ѵٴ� �ǹ�.	*/

/* size�� ������ ��� */

	v.resize(10);

	// for (auto& e : v)
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << "v[" << i << "]: " << v[i] << ", ";
	cout << endl;

	cout << "v.resize(10)�϶�, v.size(): " << v.size() << endl;
	cout << "v.resize(10)�϶�, v.capacity(): " << v.capacity() << endl;



	printf("\n");
	v.resize(2);
	
	// for (auto& e : v)
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << "v[" << i << "]: " << v[i] << ", ";
	cout << endl;

	cout << "v.resize(2)�϶�, v.size(): " << v.size() << endl;
	cout << "v.resize(2)�϶�, v.capacity(): " << v.capacity() << endl;

	/* Error
	cout << "v[2]" << v[2] << endl;
	cout << "v.at(2)" << v.at(2) << endl;
	*/

	printf("\n");
	// ������ pointer ��������
	int* ptr_v = v.data();

	cout << "ptr_v[2]: " << ptr_v[2] << endl;
	cout << "=> vector�� �� �۰� resize�� �Ҷ�, delete�� ���� �ʴ´�"  << endl;
	cout << "=> ���� ������ �ִ� �з�(capacity)�� size�� �ٸ���" << endl;
	
	// => vector�� �� �۰� resize�� �Ҷ�, delete�� ���� �ʴ´�.
	// => ���� ������ �ִ� �з�(capacity)�� size�� �ٸ���.



	
/* capacity�� ������ ���*/
	v.resize(3); // size ���󺹱�
	v.reserve(1024); // �޸��� �뷮�� �̸� Ȯ���س��ڴ�.

	printf("\ncapacity�� ������ ���\n");
	// for (auto& e : v)
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << "v[" << i << "]: " << v[i] << ", ";
	cout << endl;

	cout << "v.reserve(1024)�϶�,  v.size(): " << v.size() << endl;
	cout << "v.reserve(1024)�϶�, v.capacity(): " << v.capacity() << endl;
	cout << "=> �ڿ� ���Ұ� �߰��ɶ�, reserve�� ������ ���� �����ִٸ� �ξ� ������." << endl;





	printf("\nvector�� Stackó�� ����ϴ� ���\n");
/* vector�� Stackó�� ����ϴ� ��� - ������ ���� */
	std::vector<int> stack;

	// stack.reserve(1024);

	// stack�� ���� �ֱ�: push
	stack.push_back(3);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);
	  
	stack.push_back(7);
	printStack(stack);
	
	// stack���� ���� ������: pop
	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);


	/*
	Stack�� vector�� �����ϴ� ����
	-> vector���� reserve�� �صθ�, push_back�� �Ҷ� capacity�� �ø� �ʿ䰡 ����,
	   �׷��� new�� delete�� ȣ���� �ʿ䰡 ��� ȿ���� �� ����.
	   �ݴ�� pop�� �Ҷ��� capacity�� ������ ä��, size�� �پ��� ���·� ����� �� �ִ�.
	   �̶��� ȿ���� ����.
	   ������ reserve�� ��~�� ũ�� �صθ� capacity�� �ʹ� Ŀ��, �޸𸮰� ����� �� �ִ�.
	*/

	return 0;
}
