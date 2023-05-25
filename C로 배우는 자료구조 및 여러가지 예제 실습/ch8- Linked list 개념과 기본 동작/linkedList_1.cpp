#include <stdio.h>
#include <stdlib.h>

struct node {
	const char* data;
	struct node* next; // 자신과 동일한 구조체에 대한 포인터 : 자기참조형 구조체
};
typedef struct node Node; // 간결화
Node* head = NULL;

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;

	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;

	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head; // head의 값을 2번째 노드로 변경
	head = q; // q의 값을 1번째 노드로 변경

	Node* p = head; // head에 저장된 값을 p로 사용
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next; // 다음노드로 넘어가기 
	}
}