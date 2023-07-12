#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char myString[] = "string";	// 6문자 + NULL Character(\0)

	for (int i = 0; i < 7; ++i)
	{
		cout << myString[i] <<  endl;

	}
	cout << "size: " << sizeof(myString) / sizeof(myString[0]) << endl;


	/* cin과 할당 섞어서 사용   
	char myString2[255];
	cin >> myString2;
	

	myString2[0] = 'A';
	myString2[4] = '\0';	// cout이 (\0) 이후로 출력을 중단한다

	cout << myString2 << endl;

	*/


	/*	cin에 띄어쓰기 		   
	char myString3[255];

	cin.ignore();  // 입력 버퍼 비우기
	cin.getline(myString3, 255);

	cout << myString3 << endl;
	*/



	/* 빈칸과 \0의 차이     

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
	/*  cstring에 정의된 함수   */
	char source[] = "Copy this!";
	char dest[50];
	strcpy(dest, source);

	cout << "source: " << source << endl;
	cout << "dest: " << dest << endl;

	
	printf("\nstrcmp\n");
	// strcat(); // 뒤에 덧붙이기
	// strcmp(); // 비교. 같으면 0 return, 다르면 -1 return
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