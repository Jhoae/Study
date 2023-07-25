#include <iostream>
#include <fstream> // file stream

using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

/* #1 */
	void print()
	{
		cout << "m_x:\t" << m_x << endl;
		cout << "m_y:\t" << m_y << endl;
		cout << "m_z:\t" << m_z << endl;
	}




/* #2 출력 연산자 overloading
- return type이 std::ostream& operator << 
( ostream == output stream ) */
	friend std::ostream& operator << (std::ostream& out, const Point& point)
	{
		out << "( " << point.m_x << " " << point.m_y << " " << point.m_z << " )";

		return out;
	}


/* #4 입력 연산자 overloading 
- return type이 std::istream& operator >>
( istream == input stream ) */
	friend std::istream& operator >> (std::istream& in, Point& point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;

		return in;
	}
};


int main()
{
/* #1 기본적인 print 방법 */
	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	p1.print();
	p2.print();


	printf("\n#2 입출력 연산자 overloading을 이용한 print 방법\n");
/* #2 입출력 연산자 overloading을 이용한 print 방법 */
	cout << p1 << " " << p2 << endl;


/* #3 output stream의 장점 - file출력이 stream으로도 가능함 */
	ofstream of("out.txt");
	of << p1 << " " << p2 << endl;



	of.close();



	printf("\n#4 입력 연산자 overloading\n");
/* #4 입력 연산자 overloading */
	Point p3, p4, p5, p6;

	cin >> p3 >> p4;

	cout << p3 << " " << p4 << endl;

// "in.txt" 파일로부터 Point 객체들을 읽어옴
	ifstream inf("in.txt");
	inf >> p5 >> p6;
	
	inf.close();

	return 0;
}