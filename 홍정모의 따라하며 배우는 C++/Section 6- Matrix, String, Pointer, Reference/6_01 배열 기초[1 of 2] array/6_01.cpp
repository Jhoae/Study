#include <iostream>

using namespace std;

int main()
{

	// 선언 방식
	int one_student_score; // 1variable
	int student_scores[5]; // 5 int

	cout << sizeof(one_student_score) << endl; // 4
	cout << sizeof(student_scores) << endl;    // 20


	// 할당 방식
	one_student_score = 100;
	student_scores[0] = 100; // 1st element
	student_scores[1] = 80;  // 2nd element
	student_scores[2] = 90;  // 3rd element
	student_scores[3] = 50;  // 4th element
	student_scores[4] = 0;   // 5th element


	printf("\n");
	cout << student_scores[0] << endl;
	cout << student_scores[1] << endl;
	cout << student_scores[2] << endl;
	cout << student_scores[3] << endl;
	cout << student_scores[4] << endl;
	



	printf("\n");
	/* 구조체 Array				*/

	struct Rectangle
	{
		int length;
		int width;
	};

	cout << sizeof(Rectangle) << endl; // 8

	Rectangle rect_arr[10];
	cout << sizeof(rect_arr) << endl;  // 80

	rect_arr[0].length = 1;
	rect_arr[0].width = 2;



	printf("\n");
	/* Array 초기화 하는 방법				*/
	int my_array[5] = { 1,2,3,4,5 };
	int my_array2[] = { 1,2,3,4,5 }; // 가능
	int my_array2_1[]{ 1,2,3,4,5 };  // 가능
	int my_array3[5] = { 1,2, };     // 나머지 0

	cout << my_array[0] << endl;
	cout << my_array[1] << endl;
	cout << my_array[2] << endl;
	cout << my_array[3] << endl;
	cout << my_array[4] << endl;
	printf("\n");

	cout << my_array3[0] << endl;
	cout << my_array3[1] << endl;
	cout << my_array3[2] << endl;
	cout << my_array3[3] << endl;
	cout << my_array3[4] << endl;
	
	
	
	printf("\n");
	/* enum과 섞어쓰기			*/
	enum StudentName
	{
		JACKJACK, // 0 
		DASH,     // 1
		VIOLET,   // 2
		NUM_STUDENTS, // 3
	};

	int students_scores2[NUM_STUDENTS];

	students_scores2[JACKJACK] = 20;
	students_scores2[DASH] = 70;
	students_scores2[VIOLET] = 100;

	std::cout << students_scores2[JACKJACK] << endl;
	std::cout << students_scores2[DASH] << endl;
	std::cout << students_scores2[VIOLET] << endl;

	

	/*	cin 사용	- 권장 X	
	:: Runtime에 결정되는 cin과 달리 
	   배열은 compile time에 결정되어야 하므로 에러 발생. */
	
#define NUM_STUDENTS 10000
	
    const int num_students = 5;
//	cin >> num_students; // ERROR

	int students_scores[NUM_STUDENTS];
	int students_scores2[num_students];

	return 0;
}