#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	const char* data;
	struct node* next; // �ڽŰ� ������ ����ü�� ���� ������ : �ڱ������� ����ü
};
typedef struct node Node; // ����ȭ
Node* head = NULL;

// # �տ� ����
 
// ��
void add_first(char* item) { 
// head�� ���������� ���
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	head = temp;
}

// �� add_first(&head,item_to_store)
//void add_first(Node** ptr_head, char* item) { 
//// head�� ��������x -> head�� �ּҸ� �Ű�������
//	Node* temp = (Node*)malloc(sizeof(Node));
//	temp->data = item;
//	temp->next = *ptr_head;
//	*ptr_head = temp;
//}

// �� head = add_first(head, item_to_store)
//Node* add_first(Node* head, char* item) { 
//// head�� ��������x -> ���ο� head ����� �ּҸ� return
//	Node *temp=(Node*)malloc(sizeof(Node));
//	temp->data = item;
//	temp->next = head;
//	return temp;
//}

// # �ڿ� ����
// ���Կ� �����ϸ� 1, �ƴϸ� 0�� return
int add_after(Node* prev, char* item) {
	if (prev == NULL)
		return 0;

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;

	return 1;
}


// # head ����
Node* remove_first() {
	if (head == NULL) {
		return NULL;
	}
	else {
		Node* tmp = head;
		head = head->next;
		return tmp;
	}
}

// # � ����� ���� ��� ����
Node* remove_after(Node* prev) {
	Node* tmp = prev->next;
	if(tmp==NULL) {
		return NULL;
	}
	else {
		prev->next = tmp->next;
		return tmp;
	}
}

// #��ȸ - ���Ḯ��Ʈ�� ������ ó������ ������� �湮
// ��
Node* find(char* word) {
	Node* p = head;
	while (p != NULL) {
		if (strcmp(p->data, word) == 0)
			return p;
		p = p->next;
	}
	return NULL;
}

// ��ȸ ��
Node* get_node(int index) {
	if (index < 0)
		return NULL;
	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}



// ���� add�Լ��� remove�Լ� - ���̽����� ��ģ ���
int add(int index, char* item) {
	if (index < 0)
		return 0;

	if (index == 0) {
		add_first(item);
		return 1;
	}

	// index != 0
	Node* prev = get_node(index - 1);
	if (prev != NULL) {
		add_after(prev, item);
		return 1;
	}
	return 0;
}

Node* remove(int index) {
	if (index < 0) {
		return NULL;
	}

	if (index == 0) {
		return remove_first();
	}

	Node* prev = get_node(index - 1);
	if (prev == NULL)
		return NULL;
	else {
		return remove_after(prev);
	}
}

// item���� ã�� �����ϴ� ���: 
//	-������ ��尡 �ƴ϶� ���� ����� �ּҰ� �ʿ��� -> 2���� �����͸� ���
Node* remove(char* item) {
	Node* p = head; // ������ ���
	Node* q = NULL; // ���� ���
	while (p != NULL && strcmp(p->data, item) != 0) {
// q�� �׻� p�� ���� ��带 ����Ŵ. p�� ù��° ����ϰ��, q�� NULL
		q = p;
		p = p->next;
	}

	if (p == NULL)
		return NULL;

	if (q == NULL) // p�� head�� ���
		return remove_first();
	else
		return remove_after(q);
}


// # �������� ������ �Ǿ��ִ� �����Ϳ� ����
void add_to_ordered_list(char* item) {
	Node* p = head;
	Node* q = NULL;

	while (p != NULL && strcmp(p->data, item) <= 0) {
// Item�� ã�� ����
		q = p;
		p = p->next;
	}

	if (q == NULL) // p = head
		add_first(item);
	else
		add_after(q, item);
}