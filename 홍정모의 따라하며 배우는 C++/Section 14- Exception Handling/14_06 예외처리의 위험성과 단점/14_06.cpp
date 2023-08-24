#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	~A()
	{
/* #2 �Ҹ��� �ȿ��� throw�� ����*/
		// throw "error";
	}
};

int main()
{
	try
	{
/* #1 ������1. �޸� ó���� �ȵǼ� �޸� ������ �߻��� �� �ִ�.*/
		int* i = new int[1000000];

		unique_ptr<int> up_i(i); // �ذ�: unique pointer�� delete�� �ʿ䰡 ��������.

		// do something with i
		throw "error";

		// delete[] i;

/* #2 ���ǻ��� : �Ҹ��� �ȿ��� throw�� ����*/
		A a;
	}
	catch (...)
	{
		cout << "main() Catch" << endl;
	}

	return 0;
}
