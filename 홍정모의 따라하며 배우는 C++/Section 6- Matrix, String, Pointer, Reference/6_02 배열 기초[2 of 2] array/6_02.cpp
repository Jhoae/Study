#include <iostream>

using namespace std;

#define NUM_STUDENTS 100000

void doSomething(int students_scores[]) // pointer :: �迭�� ù�ּҸ� ������
{
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;

	printf("\nndoSomething�� �ּ�\n");
	cout << "pointer ������ �ּҰ� " << (int)&(students_scores) << endl; // pointer ������ �ּҰ�
	cout << "[0] " <<(int)&(students_scores[0]) << endl;
	cout << "[1] " <<(int)&(students_scores[1]) << endl;
	cout << "[2] " << (int)&(students_scores[2]) << endl;

	cout << "size of " << sizeof(students_scores) << endl;
}


int main()
{


	/* �޸� ��ġ�� size			 */

	const int num_students = 20;
	//	cin >> num_students; // ERROR

	int students_scores[num_students] = { 1,2,3,4,5 };

	cout << (int)students_scores << endl; // == (int)&(students_scores[0])
	cout << (int)&students_scores << endl; // == (int)&(students_scores[0])

	printf("\n�ּ�\n");
	cout << "[0] " << (int)&(students_scores[0]) << endl;
	cout << "[1] " << (int)&(students_scores[1]) << endl;
	cout << "[2] " << (int)&(students_scores[2]) << endl;

	cout << "sizeof " << sizeof(students_scores) << endl;

	printf("\ndoSomething �Լ�\n");
	doSomething(students_scores);


	return 0;
}

