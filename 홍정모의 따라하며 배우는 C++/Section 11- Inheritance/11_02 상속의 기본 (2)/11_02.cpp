#include "Student.h"
#include "Teacher.h"

int main()
{	
	Student_per student1("Jack Jack");
	student1.setName("Jack Jack 2");
	std::cout << "student1.getName():\t" << student1.getName() << std::endl;


	printf("\n");
	Teacher_per teacher1("Dr. H");
	teacher1.setName("Dr. K");
	std::cout << "teacher1.getName():\t" << teacher1.getName() << std::endl;


	printf("\n");
	std::cout << "student1:\t" << student1 << std::endl;
	std::cout << "teacher1:\t" << teacher1 << std::endl;

/* 부모 class가 가지는 함수 - doNothing() */
	printf("\n");
	student1.doNothing();
	teacher1.doNothing();


/* 각 자식 class에 속하는 함수 - study(), teach() */
	printf("\n");
	student1.study();
	teacher1.teach();


	Person person;
	person.setName("Mr. Incredible");
	person.getName();
	// error person.study()
	// error person.teach()


	return 0;
}