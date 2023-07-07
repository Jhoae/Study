#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	/* 사용 예시(ex- 게임상황 ) */
	bool item1_flag = false;
	bool item2_flag = true;
	bool item3_flag = true;
	bool item4_flag = false;
	// ...


	// event 발생!
	item1_flag = true;

	// event 발생!
	item2_flag = false;

	if (item3_flag == true)
	{
		// event
	}

	if (item3_flag == true)
	{
		item3_flag = false;
		item4_flag = false;
	}

	printf("\n");
	/*	위와 같은 상황에서 ... 	
	
	bool item1_flag = false;
	bool item2_flag = true;
	bool item3_flag = true;
	bool item4_flag = false;
	... 등 8개
	*/

	// 사용 예시
	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;

	cout << bitset<8>(opt0) << endl;	// 0000 0001
	cout << bitset<8>(opt1) << endl;	// 0000 0010
	cout << bitset<8>(opt2) << endl;	// 0000 0100
	cout << bitset<8>(opt3) << endl;	// 0000 1000

	unsigned char items_flag = 0;	
	cout << "No item " << bitset<8>(items_flag) << endl; // 0000 0000

	printf("\n");
	// event 발생 -> item0 얻음
	items_flag |= opt0;
	cout << "item0 obtained " << bitset<8>(items_flag) << endl; // 0000 0000

	printf("\n");
	// event 발생 -> item3 얻음  :: |=
	items_flag |= opt3;
	cout << "item3 obtained " << bitset<8>(items_flag) << endl; // 0000 0000

	printf("\n");
	// event 발생 -> item3 잃음  :: &= ~
	items_flag &= ~opt3;
	cout << "item3 lost " << bitset<8>(items_flag) << endl; // 0000 0000

	printf("\n");
	// item1을 갖고있는가?
	if (items_flag & opt1)
		cout << "Has item1" << endl;
	else
		cout << "NO item1" << endl;


	printf("\n");
	// item0을 갖고있는가?
	if (items_flag & opt0)
		cout << "Has item0" << endl;
	else
		cout << "NO item0" << endl;

	printf("\n");
	// event 발생 -> item2와 3을 동시에 갖게된다. :: ㅁ |= ( ㅁ | ㅁ )
	items_flag |= (opt2 | opt3);
	cout << "opt2 | opt3 " << bitset<8>(opt2 |opt3) << endl;	  // 0000 1100
	cout << "새롭게 Item2,3 얻음 + 기존 item0 " << bitset<8>(items_flag) << endl; // 0000 1101


	printf("\n");
	// XOR  :: ^
	if((items_flag & opt2) && !(items_flag & opt1)) // item2를 갖고있고, 1을 갖고있지 않을때
	{ 
		cout << "기존" << bitset<8>(items_flag) << endl; // 0000 1101
		items_flag ^= opt2;	// 2를 잃음
		items_flag ^= opt1; // 1을 얻음
		cout << "XOR :: Item2를 잃고, 1을 얻음\n" << bitset<8>(items_flag) << endl; // 0000 1101
	}


	/*  bitwise 사용ex) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	*/

	
	printf("\n");
	/* Bit masks 비트마스크		*/
	printf("비트 마스크 \n");
	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	cout << std::bitset<32>(red_mask) << endl;
	cout << std::bitset<32>(green_mask) << endl;
	cout << std::bitset<32>(blue_mask) << endl;

	
	unsigned int pixel_color = 0xDAA520; // DA: red, A5: green, 20: blue
	cout << std::bitset<32>(pixel_color) << endl;

	// 추출

	unsigned char blue = pixel_color & blue_mask;
	cout << "blue 추출\t" << bitset<8>(blue) << "\t" << int(blue) << endl;

	unsigned char green = (pixel_color & green_mask) >> 8; // 첫 8칸은 blue의 값
	cout << "green 추출\t" << bitset<8>(blue) << "\t" << int(green) << endl;

	unsigned char red = (pixel_color & red_mask) >> 16;	   // 첫 16칸은 green과 blue의 값
	cout << "red 추출\t" << bitset<8>(red) << "\t" << int(red) << endl;
	return 0;
}