#include <iostream> // cout, cin, endl ...
#include <cstdio> // printf

int main()
{
	int x=1024;
	double pi = 3.141592;

	// std::endl �� /n �� ����
	std::cout << "Hello, World!1" << std::endl;
	std::cout << "Hello, World!2\n";
	std::cout << "Hello, World!3"; // << std::endl;
	std::cout << "x is" << x << "pi is" << pi << std::endl;

	// \t�� �̿��ϸ� �ڵ� �ٸ���
	std::cout << "abc" << "\t" << "def" << std::endl;
	std::cout << "ab" << "\t" << "cdef" << std::endl;

	// ª�� ����ϱ�
	using namespace std;
	cout << "Hello, World!1" << endl;
	cout << "x is" << x << "pi is" << pi << endl;

	cout << "\a"; // ��
//	printf("Hello, World!")

	// �Է��� �޴� ���
	using namespace std;

	int y;
	cin >> y;
	cout << "Your input is " << y << endl;


	int z = 1;
	cout << "Before your input, z was " << z << endl;

	// z�� 1000000000000000000000000�� �Է��غ��� -> 2147483647 �� ��µ� (int ������ ������ �ִ� ���� ū ����)
	cin >> z; 	
	cout << "Your input is " << z << endl;


	return 0;
}