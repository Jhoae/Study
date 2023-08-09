#include <iostream>
using namespace std;

class USBDevice
{
private:
	long m_id;

public:
	USBDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;

public:
	NetworkDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(long usb_id, long net_id)
		:USBDevice(usb_id), NetworkDevice(net_id)
	{}

	/* 또는 id 하나만 받아서 2개 다 처리하는 방법 
	USBNetworkDevice(long id)
		:USBDevice(id), NetworkDevice(id)
	{} */
};




int main()
{
	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();


/* #1 모호한 호출-> 어떤 class의 getID를 호출할 것이냐?  */
	// ERROR: my_device.getID();
	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();




	return 0;
}