#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.c"


static char OPERATORS[] = "+-*/()";
static int PRECEDENCE[] = { 1,1,2,2,-1,-1 };

typedef char Item;
typedef struct stack_type* Stack;

Stack operator_stack;

int precedence(char op) {
	return PRECEDENCE[is_operator(op)];
}
int is_operator(char ch) {
	for (int i = 0; i < strlen(OPERATORS); i++)
		if (OPERATORS[i] == ch)
			return i;
	return -1;
}
void handle_exception(const char* err_msg) {
	printf("%s\n", err_msg);
	exit(1);
}

char* process_op(char op, char* pos) {
	if (is_empty(operator_stack) || op == '(')
		push(operator_stack, op);
	else {
		char top_op = peek(operator_stack);
		if (precedence(op) > precedence(top_op))
			push(operator_stack, op);
		else {
			while (!is_empty(operator_stack) && precedence(op) <= precedence(top_op)) {
				pop(operator_stack);
				if (top_op == '(')
					break;
				sprintf(pos, "%c ", top_op);				
				pos += 2;
				if (!is_empty(operator_stack))
					top_op = (char)peek(operator_stack);
			}
			if (op != ')')
				push(operator_stack, op);
		}
	}
	return pos;
}

char* convert(char* infix) {
	operator_stack = create();
	
	char* postfix = (char*)malloc(strlen(infix) + 1);
	char* pos = postfix;

	char* token = strtok(infix, " ");
	while (token != NULL) {
		if (token[0] >= '0' && token[0] <= '9') {
			sprintf(pos, "%s ", token);
			pos += (strlen(token) + 1);
		}
		else if (is_operator(token[0]) > -1) {
			pos = precess_op(token[0], pos);
		}
		else {
			printf("Syntax Error");
		}
		token = strtok(NULL, " ");
	}

	while (!is_operator(operator_stack)) {
		char op = (char)pop(operator_stack);
		if (op == '(') // error
			handle_exception("Unmatched");
		sprintf(pos, "#c ", op);
		pos += 2;
	}
	*pos = '\0';
	return postfix;
}

int main()
{
	char infix[MAX_LENGTH];
	read_line(stdin, infix, MAX_LENGTH);

	printf(" %s := ", infix);
	char* postfix = convert(infix);
	printf("%d\n", eval(postfix));
}

