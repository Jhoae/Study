/* # 동적할당 메모리를 직접 관리하는 것보단, std::vector를 사용하는것이 훨씬 편하다 */

#include <iostream>
#include <vector>

using namespace std;


/* vector를 Stack처럼 사용하는 방법 */
void printStack(const std::vector<int>& stack)
{
	for (auto& e : stack)
		cout << "Stack[" << &e << "]: " << e << ", ";
	cout << endl;
}

int main()
{
	// int *v_ptr = new int[3] {1, 2, 3}; 과 비슷하다
	std::vector<int> v{ 1,2,3 };


	
/* 	size와 capacity(용량) 
  - 코드 내부에서 용량만큼 메모리를 가지고 있지만, 
    size는 그중에서 몇개만 사용을 한다는 의미.	*/

/* size를 변경할 경우 */

	v.resize(10);

	// for (auto& e : v)
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << "v[" << i << "]: " << v[i] << ", ";
	cout << endl;

	cout << "v.resize(10)일때, v.size(): " << v.size() << endl;
	cout << "v.resize(10)일때, v.capacity(): " << v.capacity() << endl;



	printf("\n");
	v.resize(2);
	
	// for (auto& e : v)
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << "v[" << i << "]: " << v[i] << ", ";
	cout << endl;

	cout << "v.resize(2)일때, v.size(): " << v.size() << endl;
	cout << "v.resize(2)일때, v.capacity(): " << v.capacity() << endl;

	/* Error
	cout << "v[2]" << v[2] << endl;
	cout << "v.at(2)" << v.at(2) << endl;
	*/

	printf("\n");
	// 강제로 pointer 가져오기
	int* ptr_v = v.data();

	cout << "ptr_v[2]: " << ptr_v[2] << endl;
	cout << "=> vector는 더 작게 resize를 할때, delete를 하지 않는다"  << endl;
	cout << "=> 실제 가지고 있는 분량(capacity)과 size가 다르다" << endl;
	
	// => vector는 더 작게 resize를 할때, delete를 하지 않는다.
	// => 실제 가지고 있는 분량(capacity)과 size가 다르다.



	
/* capacity를 변경할 경우*/
	v.resize(3); // size 원상복구
	v.reserve(1024); // 메모리의 용량을 미리 확보해놓겠다.

	printf("\ncapacity를 변경할 경우\n");
	// for (auto& e : v)
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << "v[" << i << "]: " << v[i] << ", ";
	cout << endl;

	cout << "v.reserve(1024)일때,  v.size(): " << v.size() << endl;
	cout << "v.reserve(1024)일때, v.capacity(): " << v.capacity() << endl;
	cout << "=> 뒤에 원소가 추가될때, reserve된 공간이 많이 남아있다면 훨씬 빠르다." << endl;





	printf("\nvector를 Stack처럼 사용하는 방법\n");
/* vector를 Stack처럼 사용하는 방법 - 간단한 구현 */
	std::vector<int> stack;

	// stack.reserve(1024);

	// stack에 정보 넣기: push
	stack.push_back(3);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);
	  
	stack.push_back(7);
	printStack(stack);
	
	// stack에서 정보 꺼내기: pop
	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);


	/*
	Stack을 vector로 구현하는 이유
	-> vector에서 reserve를 해두면, push_back을 할때 capacity를 늘릴 필요가 없고,
	   그러면 new와 delete을 호출할 필요가 없어서 효율이 더 좋다.
	   반대로 pop을 할때는 capacity를 유지한 채로, size만 줄어드는 형태로 사용할 수 있다.
	   이때도 효율이 높다.
	   단점은 reserve를 너~무 크게 해두면 capacity가 너무 커서, 메모리가 낭비될 수 있다.
	*/

	return 0;
}
