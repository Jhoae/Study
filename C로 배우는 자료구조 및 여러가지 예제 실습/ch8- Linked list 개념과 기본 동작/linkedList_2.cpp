#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	const char* data;
	struct node* next; // 자신과 동일한 구조체에 대한 포인터 : 자기참조형 구조체
};
typedef struct node Node; // 간결화
Node* head = NULL;

// # 앞에 삽입
 
// ①
void add_first(char* item) { 
// head가 전역변수일 경우
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	head = temp;
}

// ② add_first(&head,item_to_store)
//void add_first(Node** ptr_head, char* item) { 
//// head가 전역변수x -> head의 주소를 매개변수로
//	Node* temp = (Node*)malloc(sizeof(Node));
//	temp->data = item;
//	temp->next = *ptr_head;
//	*ptr_head = temp;
//}

// ③ head = add_first(head, item_to_store)
//Node* add_first(Node* head, char* item) { 
//// head가 전역변수x -> 새로운 head 노드의 주소를 return
//	Node *temp=(Node*)malloc(sizeof(Node));
//	temp->data = item;
//	temp->next = head;
//	return temp;
//}

// # 뒤에 삽입
// 삽입에 성공하면 1, 아니면 0을 return
int add_after(Node* prev, char* item) {
	if (prev == NULL)
		return 0;

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;

	return 1;
}


// # head 삭제
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

// # 어떤 노드의 다음 노드 삭제
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

// #순회 - 연결리스트의 노드들을 처음부터 순서대로 방문
// ①
Node* find(char* word) {
	Node* p = head;
	while (p != NULL) {
		if (strcmp(p->data, word) == 0)
			return p;
		p = p->next;
	}
	return NULL;
}

// 순회 ②
Node* get_node(int index) {
	if (index < 0)
		return NULL;
	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}



// 최종 add함수와 remove함수 - 케이스들을 합친 결과
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

// item으로 찾아 삭제하는 방법: 
//	-삭제할 노드가 아니라 직전 노드의 주소가 필요함 -> 2개의 포인터를 사용
Node* remove(char* item) {
	Node* p = head; // 삭제할 노드
	Node* q = NULL; // 직전 노드
	while (p != NULL && strcmp(p->data, item) != 0) {
// q는 항상 p의 직전 노드를 가리킴. p가 첫번째 노드일경우, q는 NULL
		q = p;
		p = p->next;
	}

	if (p == NULL)
		return NULL;

	if (q == NULL) // p가 head일 경우
		return remove_first();
	else
		return remove_after(q);
}


// # 오름차순 정렬이 되어있는 데이터에 삽입
void add_to_ordered_list(char* item) {
	Node* p = head;
	Node* q = NULL;

	while (p != NULL && strcmp(p->data, item) <= 0) {
// Item을 찾아 전진
		q = p;
		p = p->next;
	}

	if (q == NULL) // p = head
		add_first(item);
	else
		add_after(q, item);
}