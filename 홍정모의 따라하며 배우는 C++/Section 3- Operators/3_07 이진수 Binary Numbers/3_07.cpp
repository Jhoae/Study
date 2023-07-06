/*

# 10진수	
	0
	1
	2
	3
	4
	5
	6
	7
	8
	9
	10 = 10^1 + 0
	11 = 10^1 + 1
	12
	13
	...
	337 - 300 + 30 + 7 = 10^2 * 3 + 10^1 * 3 + 10^0 * 7


# 2진수
	0
	1
	10 = 2^1 * 1 + 2^0 * 0 = 2
	11 = 2^1 * 1 + 2^0 * 1 = 3


	//2진수 더하기//

	   1
	   11
	 +  1
	 ----------
	  100






# 컴퓨터(2진수) <-> 사람(10진수)

# 2진수를 10진수로 변환하는 예제


7654 3210
0101 1110 : 8비트 1바이트 변수
= 2^7*0 + 2^6*1 + 2^5*0 + 2^4*1 + 2^3*1 + 2^2*1 + 2^1*1 + 2^0*0
= 128*0 + 64*1 + 32*0 + 16*1 + 8*1 + 4*1 + 2*1 + 1*0
= 64 + 16 + 8 + 4 + 2
= 94





# 방법1 10진수를 2진수로 변환하는 예제1 - 148 (decimal to binary)

148 / 2 = 74 r0 (r = 나머지)
74  / 2 = 37 r0
37  / 2 = 18 r1
18  / 2 = 9  r0
9   / 2 = 4  r1
4   / 2 = 2  r0
2   / 2 = 2  r0
1   / 2 = 0  r1

1001 0100 (올라가는 방향으로 읽기)




# 방법2 10진수를 2진수로 변환하는 예제2 - 148 (decimal to binary)
0 1 2 3 4  5  6  7   8   9   10
1 2 4 8 16 32 64 128 256 512 1024 ...


148 >= 128				   YES -> 128 = 2^7, 8번째 자리가 1
148 - 128 = 20, 20 >= 64   NO  -> 64  = 2^6, 7번째 자리가 0
                20 >= 32   NO  -> 32  = 2^5, 6번째 자리가 0
                20 >= 16   YES -> 16  = 2^4, 5번째 자리가 1 
20 - 16 = 4,     4 >= 8    NO  -> 8   = 2^3, 4번째 자리가 0
				 4 >= 4    YES -> 4   = 2^2, 3번째 자리가 1
4 - 4 = 0        0 >= 2	   NO  -> 2   = 2^1, 2번째 자리가 0
                 0 >= 1    NO  -> 1   = 2^0, 1번째 자리가 0
=> 1001 0100




# 2진수끼리 더하기 
	11
	0110 = 6(10진수)
	0111 = 7(10진수)
	----------------
	1101 = 13




# 2진수의 음의 정수 표현

-5  (10진수)


순서1. 5 = 0000 0101
순서2. 보수(complement)를 취한다 
      =>  1111 1010 
순서3. 1을 더한다
      =>  1111 1011
순서4. 1111 1011 == -5


※ signed int일때 2진수의 맨 앞자리는 부호를 표현하는 자리이다. 
( "0이면 양수, 1이면 음수" 를 의미)


# 1을 더하는 이유 : 0 표현

0000 0000 ( 양의 정수 0) 
-> 보수를  취한다 
-> 1111 1111 
-> 1을 더한다 
-> 0000 0000 ( 음의 정수 0)



# 음의 정수(2진수) -> 양의 정수(10진수) 로 바꾸는 방법
signed int 일때 맨 앞이 1이면 = 음수

   1001 1110
-> 보수를 취한다
-> 0110 0001
-> 1을 더한다
-> 0110 0010
-> 10진수로 바꾸면 98. 부호는 (-)
-> -98


# singed VS unsigned -> 부호문제 때문에 차이난다.

unsigned
1001 1110 -> 2^7*1 + 2^4*1 + 2^3*1 + 2^2*1 + 2^1*1 = 128 + 16 + 8 + 4 + 2 = 158

signed 
1001 1110 -> -98


*/
