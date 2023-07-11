#include <iostream>

using namespace std;

#define NUM_STUDENTS 100000

void doSomething(int students_scores[]) // pointer :: 배열의 첫주소를 가져옴
{
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;

	printf("\nndoSomething의 주소\n");
	cout << "pointer 변수의 주소값 " << (int)&(students_scores) << endl; // pointer 변수의 주소값
	cout << "[0] " <<(int)&(students_scores[0]) << endl;
	cout << "[1] " <<(int)&(students_scores[1]) << endl;
	cout << "[2] " << (int)&(students_scores[2]) << endl;

	cout << "size of " << sizeof(students_scores) << endl;
}


int main()
{


	/* 메모리 위치와 size			 */

	const int num_students = 20;
	//	cin >> num_students; // ERROR

	int students_scores[num_students] = { 1,2,3,4,5 };

	cout << (int)students_scores << endl; // == (int)&(students_scores[0])
	cout << (int)&students_scores << endl; // == (int)&(students_scores[0])

	printf("\n주소\n");
	cout << "[0] " << (int)&(students_scores[0]) << endl;
	cout << "[1] " << (int)&(students_scores[1]) << endl;
	cout << "[2] " << (int)&(students_scores[2]) << endl;

	cout << "sizeof " << sizeof(students_scores) << endl;

	printf("\ndoSomething 함수\n");
	doSomething(students_scores);


	return 0;
}

