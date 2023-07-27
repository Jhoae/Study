#pragma once

#include <vector>
#include "Student.h"
#include "Teacher.h"


/* #1 구성 관계 Composition Relationship 로 구현 */
class Lecture
{
private:
	std::string m_name;


// 소멸자와 상관없이 teacher와 students는 Lecture의 instance가 사라질때 같이 사라진다.
	Teacher teacher;
	std::vector<Student> students;

	// Teacher *teacher;
	// std::vector<Student*> students;

public:
	Lecture(const std::string& name_input)
		:m_name(name_input)
	{}

	~Lecture()
	{
		// do Not delete teacher
		// do Not delete Student
	}

	void assignTeacher(const Teacher& const teacher_input)
	{
		teacher = teacher_input;
	}

	/*
	void assignTeacher(Teacher* const teacher_input)
	{
		teacher = teacher_input;
	}
	*/

	void registerStudent(const Student& const student_input)
	{
		students.push_back(student_input);

		// 복사하여 넣기 때문에 &student_input과 &students[0]이 다르다.
		// -> 주소를 받아오도록 함수를 변경. ( Lecture_update class에서 구현 )

	}

	/*
	void registerStudent(Student* const student_input)
	{
		students.push_back(student_input);
	}
	*/

	void study()
	{
		std::cout << m_name << " Study " << std::endl << std::endl;

		// Note: 'auto element' doesn't work. &(ref)가 필요함.
		for (auto& element : students) 
			element.setIntel(element.getIntel() + 1);

		/* Doesn't work
		for (auto element : students) 
			(*element).setIntel((*element).getIntel() + 1);
		*/
	}

	friend std::ostream& operator << (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;

		out << lecture.teacher << std::endl;

		for (auto element : lecture.students)
			out << element << std::endl;

		/*
		out << *lecture.teacher << std::endl;

		for (auto element : lecture.students)
			out << *element << std::endl;
		*/
		return out;
	}
};


/* #2 집합 관계 Aggregation Relationship
	-> 주소를 받아오도록 변경 */

class Lecture_update
{
private:
	std::string m_name;

	Teacher *teacher;
	std::vector<Student*> students;

public:
	Lecture_update(const std::string& name_input)
		:m_name(name_input)
	{}

	~Lecture_update()
	{
		// do Not delete teacher
		// do Not delete Student
	}

	void assignTeacher(Teacher* const teacher_input)
	{
		teacher = teacher_input;
	}

	void registerStudent(Student* const student_input)
	{
		students.push_back(student_input);
	}

	void study()
	{
		std::cout << m_name << " Study " << std::endl << std::endl;

		// for (auto &element : students)도 가능
		for (auto element : students)
			(*element).setIntel((*element).getIntel() + 1);
			// == element->setIntel(element->getIntel() + 1
	}

	friend std::ostream& operator << (std::ostream& out, const Lecture_update& lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;

		out << *lecture.teacher << std::endl;

		for (auto element : lecture.students)
			out << *element << std::endl;
		return out;
	}
};