#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT.h"
#include "pos.h"

#define INIT_CAPACITY 100

typedef pos Item;
typedef struct stack_type* Stack;

struct stack_type
{
	pos* contents;
	int top;
	int size;
};

static void terminate(const char* message)
{
	printf("%s\n", message);
	exit(1);
}

Stack create()
{
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL) {
		terminate("Error in create.");
	}
	s->contents = (Item*)malloc(INIT_CAPACITY * sizeof(Item));
	if (s->contents == NULL) {
		free(s);
		terminate("Error in create.");

	}
	s->top = -1;
	s->size = INIT_CAPACITY;
	return s;
}

void destroy(Stack s) {
	free(s->contents);
	free(s);
}

void make_empty(Stack s) {
	s->top = -1;
}

bool is_empty(Stack s) {
	return s->top == -1;
}

