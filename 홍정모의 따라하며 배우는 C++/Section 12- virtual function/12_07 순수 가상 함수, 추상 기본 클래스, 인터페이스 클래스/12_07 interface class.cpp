// 내부의 함수가 모두 순수 가상 함수일 경우에 interface class라고 한다
// -> 실제로 구현한것은 없고, 무엇을 해야하는지만 예측할 수 있게 정해둔 것.

#include <iostream>
#include <string>
using namespace std;

class IErrorLog
{
public:
	virtual bool reportError(const char* errorMessage) = 0;

	virtual ~IErrorLog() {}
};

class FileErrorLog :public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog :public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!!!");
}

int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}