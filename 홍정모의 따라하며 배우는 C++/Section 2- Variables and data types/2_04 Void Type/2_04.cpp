
void my_function()
{

}

int main()
{
	// void my_void; // Error
	int i = 123;
	float f = 123.456f;

	/*	data type�� size�� �ٸ�����, �� �������� �ּҸ� ǥ���ϴ� data���� �����ϴ�		*/

	// Void Pointer. 
	void* my_void;

	my_void = (void*)&i;	// ������ ������ �ּ�
	my_void = (void*)&f;	// �Ǽ��� ������ �ּ�

}