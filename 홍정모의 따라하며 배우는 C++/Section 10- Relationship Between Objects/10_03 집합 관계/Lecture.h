#pragma once

#include <vector>
#include "Student.h"
#include "Teacher.h"


/* #1 ���� ���� Composition Relationship �� ���� */
class Lecture
{
private:
	std::string m_name;


// �Ҹ��ڿ� ������� teacher�� students�� Lecture�� instance�� ������� ���� �������.
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

		// �����Ͽ� �ֱ� ������ &student_input�� &students[0]�� �ٸ���.
		// -> �ּҸ� �޾ƿ����� �Լ��� ����. ( Lecture_update class���� ���� )

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

		// Note: 'auto element' doesn't work. &(ref)�� �ʿ���.
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


/* #2 ���� ���� Aggregation Relationship
	-> �ּҸ� �޾ƿ����� ���� */

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

		// for (auto &element : students)�� ����
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