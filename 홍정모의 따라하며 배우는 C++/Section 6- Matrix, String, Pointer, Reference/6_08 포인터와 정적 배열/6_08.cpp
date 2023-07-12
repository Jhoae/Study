#include <iostream>

using namespace std;

void printArray(int array[])
// == void printArray(int *array)
// 매개변수를 array로 받더라도 결국 pointer로 사용하게 된다.
{
	// 4bytes
	cout << "printArray() sizeof: " << sizeof(array) << endl; //
	cout << "printArray() *array: " << *array << endl; //
	
	*array = 100;
}

struct MyStruct
{
	int array[5] = { 9,7,5,3,1 };
};

void doSomething(MyStruct ms)
{
	cout <<"doSomething() sizeof(ms.array): " << sizeof(ms.array) << endl;
}
void doSomething2(MyStruct *ms)
{
	cout << "doSomething2() sizeof((*ms).array): " << sizeof((*ms).array) << endl;
}



int main()
{
	/* 정적 array와 pointer는 대부분 같다			 */
	int array[5] = { 9,7,5,3,1 };

	cout << array[0] << " " << array[1] << endl;
	cout << "array:\t\t" << array << endl;
	cout << "&array[0]:\t" << &array[0] << endl;

	cout << "*array: " << *array << endl;


	printf("\n");
	char name[] = "jackjack";
	cout << "*name: " << *name << endl;

	int* ptr = array;
	cout << "ptr: " << ptr << endl;
	cout << "*ptr: " << *ptr << endl;






	printf("\n");
	/* pointer와 정적array의 차이점	*/

	int array2[5] = {9,7,5,3,1};
	// 20bytes
	cout << "sizeof(array): " << sizeof(array) << endl; 

	int* ptr3 = array2;
	// 4bytes
	cout << "sizeof(ptr3): " << sizeof(ptr3) << endl; 

	printArray(array); // 4 , 9
	printArray(ptr3);  // 4 , 9
	

	/* 함수 안에서 값을 바꿔도 
	함수 밖에서도 값이 바뀐채로 유지된다	*/
	cout << array[0] << " " << *array << endl;


	/* pointer 연산			*/
	cout << *ptr << " " << *(ptr + 1) << endl;
	


	printf("\n");
	/* 구조체struct속 배열  */

	MyStruct ms;
	cout << ms.array[0] << endl;
	cout << "main() sizeof(ms.array): " << sizeof(ms.array) << endl;

	doSomething(ms);
	doSomething2(&ms);


	return 0;
}