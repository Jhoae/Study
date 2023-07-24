#include "Calc.h"

int main()
{
	// 规过 ㄧ
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print();

	// 规过 ㄨ
	Calc(10).add(10).sub(1).mult(2).print();

	return 0;
}