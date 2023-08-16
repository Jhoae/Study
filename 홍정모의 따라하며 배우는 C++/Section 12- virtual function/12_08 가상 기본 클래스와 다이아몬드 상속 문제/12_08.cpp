#include <iostream>
using namespace std;

/* #1 virtual이 없을 경우*/
class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
	{
		cout << "PoweredDevice: " << power << '\n';
	}
};

class Scanner : public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		:PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << '\n';
	}
};

class Printer : public PoweredDevice
{
public:
	Printer(int printer, int power)
		:PoweredDevice(power)
	{
		cout << "Printer: " << printer << '\n';
	}
};

class Copier: public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		:Scanner(scanner, power), Printer(printer, power)
	{
	}
};


/* #2 virtual keyword*/
class PoweredDevice_virt
{
public:
	int m_i;

	PoweredDevice_virt(int power)
	{
		cout << "PoweredDevice_virt: " << power << '\n';
	}
};

class Scanner_virt : virtual public PoweredDevice_virt
{
public:
	Scanner_virt(int scanner, int power)
		:PoweredDevice_virt(power)
	{
		cout << "Scanner_virt: " << scanner << '\n';
	}
};

class Printer_virt : virtual public PoweredDevice_virt
{
public:
	Printer_virt(int printer, int power)
		:PoweredDevice_virt(power)
	{
		cout << "Printer_virt: " << printer << '\n';
	}
};

class Copier_virt : public Scanner_virt, public Printer_virt
{
public:
	Copier_virt(int scanner, int printer, int power)
		:Scanner_virt(scanner, power), Printer_virt(printer, power),
		PoweredDevice_virt(power)
	{
	}
};


int main()
{
	printf("#1 virtual keyword가 없을 경우\n");
	Copier cop(1, 2, 3);


	cout << "&cop.Scanner::PoweredDevice::m_i:\t " 
		<< &cop.Scanner::PoweredDevice::m_i << endl;
	
	cout << "&cop.Printer::PoweredDevice::m_i:\t " 
		<< &cop.Printer::PoweredDevice::m_i << endl;



	printf("\n#2 virtual keyword가 있는 경우\n");

	Copier_virt cop_virt(4, 5, 6);
	cout << "&cop_virt.Scanner_virt::PoweredDevice_virt::m_i:\t "
		<< &cop_virt.Scanner_virt::PoweredDevice_virt::m_i << endl;

	cout << "&cop_virt.Printer_virt::PoweredDevice_virt::m_i:\t "
		<< &cop_virt.Printer_virt::PoweredDevice_virt::m_i << endl;

	return 0;
}