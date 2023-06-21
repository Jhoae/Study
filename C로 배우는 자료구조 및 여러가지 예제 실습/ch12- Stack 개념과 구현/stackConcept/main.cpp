#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char OPEN[] = "([{";
char CLOSE[] = ")]}";

int is_balanced(char* expr);
int is_open(char ch);
int is_close(char ch);

int main()
{
	char expr[MAX_LENGTH];
	scanf("%s", expr);
	if (is_balanced(expr))
		printf("%s: balanced.\n", expr);
	else 
		printf("%s: unbalanced.\n", expr);
}

