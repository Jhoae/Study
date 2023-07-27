#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

int main()
{
	using namespace std;

/* #1 구성 관계 Composition Relationship 로 구현 */
	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(Teacher("Prof. Hong"));
	lec1.registerStudent(Student("Jack Jack", 0)); // ①
	lec1.registerStudent(Student("Dash", 1));
	lec1.registerStudent(Student("Violet", 2));

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(Teacher("Prof. Good"));
	lec2.registerStudent(Student("Jack Jack", 0)); // ②
	// ①과 ②의 주소가 다르다.


	// TODO: implement Aggregation Relationship


	// test
	{
		cout << "lec1:\t" << lec1 << endl;
		cout << "lec2:\t" << lec2 << endl;

		// event
		lec2.study(); // 학생들의 숫자가 1씩 올라감

		cout << "lec1:\t" << lec1 << endl;
		cout << "lec2:\t" << lec2 << endl;
	}

	printf("\n#2 집합 관계 Aggregation Relationship\n");
/* #2 집합 관계 Aggregation Relationship */
	Student std1("Jack Jack", 0);
	Student std2("Dash", 1);
	Student std3("Violet", 2);

	Teacher teacher1("Prof. Hong");
	Teacher teacher2("Prof. Good");

	Lecture_update lec3("Aggregation Relationship class");
	lec3.assignTeacher(&teacher1);
	lec3.registerStudent(&std1);
	lec3.registerStudent(&std2);
	lec3.registerStudent(&std3);

	Lecture_update lec4("Composition Relationship class");
	lec4.assignTeacher(&teacher2);
	lec4.registerStudent(&std1);

	// test
	{
		cout << "lec3:\t" << lec3 << endl;
		cout << "lec4:\t" << lec4 << endl;

		// event
		lec4.study(); // 학생들의 숫자가 1씩 올라감

		cout << "lec3:\t" << lec3 << endl;
		cout << "lec4:\t" << lec4 << endl;
	}

	printf("\n#3 instance를 다른곳에서 쓸 수도 있으므로 동적할당으로 구현하기도 한다.\n");
/* #3 instance를 다른곳에서 쓸 수도 있으므로 동적할당으로 구현하기도 한다. */
	Student *std1_m = new Student("Jack Jack", 0);
	Student *std2_m = new Student("Dash", 1);
	Student *std3_m = new Student("Violet", 2);

	Teacher *teacher1_m = new Teacher("Prof. Hong");
	Teacher *teacher2_m = new Teacher("Prof. Good");

	Lecture_update lec5("temp class 1 ");
	lec5.assignTeacher(teacher1_m);
	lec5.registerStudent(std1_m);
	lec5.registerStudent(std2_m);
	lec5.registerStudent(std3_m);

	Lecture_update lec6("Temp class 2 ");
	lec6.assignTeacher(teacher2_m);
	lec6.registerStudent(std1_m);


	{
		cout << "lec5:\t" << lec5 << endl;
		cout << "lec6:\t" << lec6 << endl;

		// event
		lec6.study(); // 학생들의 숫자가 1씩 올라감

		cout << "lec5:\t" << lec5 << endl;
		cout << "lec6:\t" << lec6 << endl;
	}

	// 동적 할당은 delete memory
	delete std1_m;
	delete std2_m;
	delete std3_m;

	delete teacher1_m;
	delete teacher2_m;


}