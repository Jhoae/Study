#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char* data;
	struct node* next;
	struct node* prev;
};

typedef struct node Node;

Node* head;
Node* tail;

int size = 0;

// 기본 add와 remove
void add(Node * p) {
	if (p == NULL) {
		return;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = "Sharon";
	new_node->next = p;
	new_node->prev = p->prev;
	p->prev->next = new_node;
	p->prev = new_node;
}
void remove(Node* p) {
	p->prev = p->next;
	p->next->prev = p->prev;
}

void add_after(Node* pre, char* item) { 
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	new_node->prev = NULL;
	new_node->next = NULL;

	// 빈 배열에 Node를 추가하는 경우
	if (pre == NULL && head == NULL) {
		head = new_node;
		tail = new_node;
	}

	// head에 Node를 추가하는 경우
	else if (pre == NULL && head != NULL) {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}

	// tail에 Node를 추가하는 경우
	else if (pre == tail) {
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}

	// Node사이에 Node를 추가하는 경우
	else {
		new_node->prev = pre;
		new_node->next = pre->next;
		pre->next->prev = new_node;
		pre->next = new_node;
	}
	size++;
}

void remove_4cases(Node* p) {
	// p가 유일한 노드인 경우
	if (p == head && p == tail) {
		head = NULL;
		tail = NULL;
	}

	// p가 head인 경우
	if (p == head) {
		p->next->prev = NULL;
		head = p->next;
	}

	// P가 tail인 경우
	if (p == tail) {
		p->prev->next = NULL;
		tail = p->prev;
	}

	// 그 밖의 일반적인 경우
	else {
		remove(p);
	}
}

// 정렬되어있는 배열에 Node를 추가하는 경우
void add_ordered_list(char* item) {
	Node* p = tail;
	while (p != NULL && strcmp(item, p->data) < 0) {
		p = p->prev;
	}
	add_after(p, item);
}
