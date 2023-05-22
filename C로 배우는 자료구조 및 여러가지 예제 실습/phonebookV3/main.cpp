#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3
#define BUFFER_SIZE 50

char** names;
char** numbers;

int capacity = INIT_CAPACITY; // 배열의 size
int n = 0; // 배열에 저장된 사람수

char delim[] = " ";

void add(char*, char*);
void load(char *);
void save(char* );
void status();
void find(char* );
int search(char* );
void remove(char* );

int read_line(char str[], int limit);
void init_directory();


int main() {
	init_directory(); // 이 함수에서 배열 names와 numbers를 생성한다.
	process_command();
}

void init_directory() {
	names = (char**)malloc(INIT_CAPACITY * sizeof(char*));
	numbers = (char**)malloc(INIT_CAPACITY * sizeof(char*));
}
int read_line(char str[], int limit)
{
// line단위 입력은 fgets, getline 등의 함수로도 가능
// limit은 배열 str의 크기
// 즉 limit보다 더 긴 line의 경우, 뒷부분이 잘린다.
	int ch, i = 0;

	while ((ch = getchar()) != '\n') // 줄바꿈 문자가 나올때까지 읽는다.
		if (i < limit - 1) // 배열의 용량을 초과하지 않을 때만 저장.
			str[i++] = ch;

	str[i] = '\0'; // 마지막에 null character('\0')를 추가

	return i; // 실제로 읽은 문자수를 반환
}

void process_command() {
	char command_line[BUFFER_SIZE]; // 한 라인을 통채로 읽어오기 위한 버퍼
	char* command, * argument1, * argument2;

	while (1) {
		printf("$ ");

		if (read_line(command_line, BUFFER_SIZE) <= 0) // 명령줄을 통채로 읽는다
			continue; // 다시 while문 반복

		command = strtok(command_line, delim); // 첫번째 토큰은 명령어이다.
		if (command == NULL) continue;

		if (strcmp(command, "read") == 0) {
			argument1 = strtok(NULL, delim); // read 명령에서 두번째 토큰은 파일명이다

			if (argument1 == NULL) {
				printf("File name required.\n");
				continue;
			}
			load(argument1); // 파일명을 인자로 주면서 load를 호출
		}
		else if (strcmp(command, "add") == 0) {
			// 명령어에 이어지는 2개의 토큰은 각각 이름과 전화번호이다.
			argument1 = strtok(NULL, delim);
			argument2 = strtok(NULL, delim);

			if (argument1 == NULL || argument2 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}

			// 이름과 전화번호를 인자로 주면서 add를 호출한다.
			add(argument1, argument2);
			printf("%s was added successfully.\n");
		}
		else if (strcmp(command, "find") == 0) {
			argument1 = strtok(NULL, delim);
			if (argument1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			find(argument1);
		}
		else if (strcmp(command, "status") == 0) {
			status();
		}
		else if (strcmp(command, "delete") == 0) {
			argument1 = strtok(NULL, delim);
			if (argument1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			remove(argument1);
		}
		else if (strcmp(command, "save") == 0) {
			argument1 = strtok(NULL, delim);
			argument2 = strtok(NULL, delim);

			if (argument1 == NULL || strcmp("as", argument1) != 0 || argument2 == NULL) {
				printf("Invalid command format.\n");
				continue;
			}
			save(argument2);
		}
		else if (strcmp(command, "exit") == 0)
			break;
	} 

}


void add(char* name, char* number) {
	
// 배열이 꽉찬 경우, 재할당한다.
	if (n >= capacity)
		reallocate();

// 알파벳순 정렬
	int i = n - 1;
	while (i >= 0 && strcmp(names[i], name) > 0) {
		names[i + 1] = names[i];
		numbers[i + 1] = numbers[i];
		i--;
	}

// strdup가 필요한 이유 : name과 number 매개변수가 지역변수이므로 사라져버리기 때문에 복제해두어야 한다.
	names[i + 1] = strdup(name);
	numbers[i + 1] = strdup(number);
	n++;
}
void load(char *fileName) {
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];

	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	while ((fscanf(fp, "%s", buf1) != EOF)) {
		fscanf(fp, "%s", buf2);
		add(buf1, buf2);
	}
	fclose(fp);
}
void save(char* fileName) {
	int i;
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}

	for (i = 0; i < n; i++) {
		fprintf(fp, "%s %s\n", names[i], numbers[i]);
	}
	fclose(fp);
}
void remove(char* name) {
	int i = search(name); // 존재하지 않으면 return -1 
	if (i == -1) {
		printf("No person named '%s' exists.\n", name);
		return;
	}

	int j = i;
	for (; j < n - 1; j++) {
		names[j] = names[j + 1];
		numbers[j] = numbers[j + 1];
	}
	n--;
	printf("'%s' was deleted successfully. \n", name);
}
void status() {
	int i;
	for (i = 0; i < n; i++)
		printf("%s  %S\n", names[i], numbers[i]);
	printf("Total %d persons.\n", n);
}
void find(char* name) {
	int index = search(name);
	if (index == -1)
		printf("No person named '%s exists.\n", name);
	else
		printf("%s\n", numbers[index]);
}
int search(char* name) {
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(name, names[i]) == 0) {
			return i;
		}
	}
	return -1;
}
void reallocate() {
	int i;

// 먼저크기가 2배인 배열들을 할당한다..
	capacity *= 2;
	char** tmp1 = (char**)malloc(capacity * sizeof(char*));
	char** tmp2 = (char**)malloc(capacity * sizeof(char*));

// 원본 배열 names와 numbers의 값을 새로운 배열에 복사한다.
	for (i = 0; i < n; i++) {
		tmp1[i] = names[i];
		tmp2[i] = numbers[i];
	}

// 원본 배열 names와 numbers는 더 이상 필요없다. 
//	하지만 두 배열은 init_directory() 함수에서 동적메모리 할당으로 만들어진 배열이므로
// 그냥두면 없어지지 않고 계속 존재한다. 이런 메모리를 garbage라고 부른다.
// garbage는 free함수를 이용하여 반환한다.

	free(names);
	free(numbers);

// names와 numbers가 새로운 배열을 가리키도록 한다.
// (배열의 이름은 포인터 변수이다.)
	names = tmp1;
	numbers = tmp2;
}