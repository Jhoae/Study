#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
	Item data;
	struct node* next;
};

struct queue_type {
	struct node* front;
	struct node* rear;
	int size;
};

void terminate(const char* message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

int get_size(Queue q) {
	return q->size;
}

Queue create()
{
	Queue q = (Queue)malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create");
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return q;
}

void destroy(Queue q)
{
	make_empty(q);
	free(q);
}

void make_empty(Queue q)
{
	while (!is_empty(q))
		dequeue(q);
	q->size = 0;
}

bool is_empty(Queue q)
{
	return q->front == NULL;
	// return q->size == 0
}

void enqueue(Queue q, Item i)
{
	struct node* new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in enqueue");

	new_node->data = i;
	new_node->next = NULL;

	if (q->front == NULL) { // empty list일 경우, 
		q->front = new_node;
		q->rear = new_node;
	}
	else {
		q->rear->next = new_node; // 이전 rear의 앞 = new_node
		q->rear = new_node; // rear가 가리키는 node를 new_node로 변경
	}
	q->size++;
}

Item dequeue(Queue q)
{
	struct node* old_front;
	Item i;
	if (is_empty(q))
		terminate("Error in dequeue");

	old_front = q->front; // old_front = f
	i = old_front->data; 
	// f가 가리키는 노드를 삭제할 노드의 다음 노드로 변경
	q->front = old_front->next; 

// old_front를 삭제했더니 빈 노드가 된 경우 == old_front가 유일한 node였을 경우
	if (q->front == NULL) 
		q->rear = NULL;

	free(old_front);
	q->size--;
	return i;
}

Item peek(Queue q)
{
	if (is_empty(q))
		terminate("Error in peek");

	return q->front->data;
}