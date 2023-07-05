
void my_function()
{

}

int main()
{
	// void my_void; // Error
	int i = 123;
	float f = 123.456f;

	/*	data type의 size가 다르더라도, 그 데이터의 주소를 표현하는 data양은 동일하다		*/

	// Void Pointer. 
	void* my_void;

	my_void = (void*)&i;	// 정수형 변수의 주소
	my_void = (void*)&f;	// 실수형 변수의 주소

}