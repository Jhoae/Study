#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Doctor; // 전방 선언

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors;

public:
	Patient(string name_in)
		:m_name(name_in)
	{}
	
	void addDoctor(Doctor* new_Doctor)
	{
		m_doctors.push_back(new_Doctor);
	}

	void meetDoctors(); // 아직 Doctor의 m_name에 접근할 수 없으므로 선언만

	friend class Doctor; // Doctor의 meet Patient()에서 member 접근 가능하게 만들기 위해
};

class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patients;

public:
	Doctor(string name_in)
		:m_name(name_in)
	{}

	void addPatient(Patient* new_Patient)
	{
		m_patients.push_back(new_Patient);
	}

	void meetPatients()
	{
		for (auto& ele : m_patients)
		{
			cout << "Meet patient : " << ele->m_name << endl;
		}
	}

	friend class Patient; // Patient의 meet Doctor()에서 member 접근 가능하게 만들기 위해
};


// Patient class에서 선언한 meetDoctors함수 정의
void Patient::meetDoctors()
{
	for (auto& ele : m_doctors)
	{
		cout << "Meet doctor : " << ele->m_name << endl;
	}
}



int main()
{
	Patient* p1 = new Patient("Jack Jack");
	Patient* p2 = new Patient("Dash");
	Patient* p3 = new Patient("Violet");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");


	p1->addDoctor(d1);
	d1->addPatient(p1);

	
	p2->addDoctor(d1);
	d1->addPatient(p2);



	printf("#1 meetDoctors()\n");
/* #1 */
	p1->meetDoctors();



	printf("\n#2 meetPatients()\n");
/* #2 */
	d1->meetPatients();



	// deletes memory
	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;


	return 0;
}