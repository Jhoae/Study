#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char myString[] = "string";	// 6���� + NULL Character(\0)

	for (int i = 0; i < 7; ++i)
	{
		cout << myString[i] <<  endl;

	}
	cout << "size: " << sizeof(myString) / sizeof(myString[0]) << endl;


	/* cin�� �Ҵ� ��� ���   
	char myString2[255];
	cin >> myString2;
	

	myString2[0] = 'A';
	myString2[4] = '\0';	// cout�� (\0) ���ķ� ����� �ߴ��Ѵ�

	cout << myString2 << endl;

	*/


	/*	cin�� ���� 		   
	char myString3[255];

	cin.ignore();  // �Է� ���� ����
	cin.getline(myString3, 255);

	cout << myString3 << endl;
	*/



	/* ��ĭ�� \0�� ����     

	char myString4[255];
	cin.getline(myString4, 255);

	int ix = 0;
	while (true)
	{
		if (myString4[ix] == '\0') break;

		cout << myString4[ix] << " " << (int)myString4[ix] << endl;
		++ix;
	}

	*/

	printf("\nstrcpy\n");
	/*  cstring�� ���ǵ� �Լ�   */
	char source[] = "Copy this!";
	char dest[50];
	strcpy(dest, source);

	cout << "source: " << source << endl;
	cout << "dest: " << dest << endl;

	
	printf("\nstrcmp\n");
	// strcat(); // �ڿ� �����̱�
	// strcmp(); // ��. ������ 0 return, �ٸ��� -1 return
	if (strcmp(source, dest) == 0)
	{
		cout << "source, dest: equal" << endl;
	}



	printf("\nstrcat\n");
	strcat(dest, " add");

	cout << "source: " << source << endl;
	cout << "dest: " << dest << endl;



	return 0;
}