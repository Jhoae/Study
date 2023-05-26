#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_POLYS 10
#define BUFFER_LENGTH 100

struct term {
	int coef;
	int expo;
	struct term* next;
};
typedef term Term;

typedef struct polynomial {
	char name;
	Term* first;
	int	size = 0;
} Polynomial;

Polynomial* polys[MAX_POLYS];
int n = 0;

Term* create_term_instance() {
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;

	return t;		
}

Polynomial* create_polynomial_instance(char name) {
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;

	return ptr_poly;
}

void add_term(int c, int e, Polynomial* poly) { // cx^e
	if (c == 0)
		return;
	
	//전진
	Term* p = poly->first, * q = NULL;
	while (p != NULL && p->expo > e) {
		q = p;
		p = p->next;
	}

	// 동일 차수의 항이 존재하는 경우
	if (p != NULL && p->expo == e) { 
		p->coef = p->coef + c;
		if (p->coef == 0) { // 더하니 계수가 0
			if (q == NULL) // p가 첫 노드
				poly->first = p->next; // 첫 노드 삭제
			else
				q->next = p->next; // p가 가리키는 노드 삭제
			poly->size--;
			free(p);
		}
		return;
	}

	// 동일 차수의 항이 존재하지 않는 경우
	Term* term = create_term_instance();
	term->coef = c;
	term->expo = e;

	if (q == NULL) { // 맨앞에 삽입
		term->next = poly->first;
		poly->first = term;
	}
	else { // q의 뒤, p의 앞에 삽입
		term->next = p;
		q->next = term;
	}
	poly->size++;
}

void print_term(Term * pTerm) {

	if (pTerm->coef == 0) // 계수가 0
		return;

	// 계수가 +
	if (pTerm->coef > 0) {
		printf("+");
		if (pTerm->expo == 0)  // x^0
			printf("%d", pTerm->coef);
		else if (pTerm->expo == 1) // x^1
			printf("%dx", pTerm->coef);
		else
			printf("%dx^%d", pTerm->coef, pTerm->expo);
	}

	// 계수가 -
	if (pTerm->coef < 0) {
		printf("-");
		if (pTerm->expo == 0)  // x^0
			printf("%d", pTerm->coef);
		else if (pTerm->expo == 1) // x^1
			printf("%dx", pTerm->coef);
		else
			printf("%dx^%d", pTerm->coef, pTerm->expo);
	}
}

int eval_term(Term* term, int x) {
	int result = term->coef;
	for (int i = 0; i < term->expo; i++) {
		result *= x;
	}

	return result;
}
int eval_polynomial(Polynomial* poly, int x) { // 다항식의 값을 계산
	int result = 0;
	Term* t = poly->first;
	while (t != NULL) {
		result += eval_term(t, x);
		t = t->next;
	}
	return result;
}

void print_poly(Polynomial* p) {
	printf("%c=", p->name);
	
	Term* t = p->first;
	while (t != NULL) {
		print_term(t);
	//	printf("+");		
		t = t->next;
	}
}

int read_line(FILE* fp, char str[], int n) {
	int ch, i = 0;

	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
		if (i < n)
			str[i++] = ch;

	str[i] = '\0';
	return i;
}

void handle_print(char name) {

}
void handle_calc(char name, char* x_str) {

}
void erase_blanks(char* expression) {

}

Term* parse_and_add_term(char* expr, int begin, int end, Polynomial* p_poly) {
	int i = begin;
	int sign_coef = 1, coef = 0, expo = 1;
	if (expr[i] == '+')
		i++;
	else if (expr[i] == '-') {
		sign_coef = -1;
		i++;
	}

	while (i < end && expr[i] >= '0' && expr[i] <= '9') {
		coef = coef * 10 + (int)(expr[i] = '0'); // ex) '2315' -> 2315
		i++;
	}
	if (coef == 0)
		coef = sign_coef;
	else coef *= sign_coef;

	if (i >= end) {
		add_term(coef, 0, p_poly);
	}
	if()
}
Polynomial* create_by_parse_polynomial(char name, char* body) {
	Polynomial* ptr_poly = create_polynomial_instance(name);

	int i = 0, begin_term = 0;
	while (i < strlen(body)) {
		if (body[i] == '+' || body[i] == '-')
			i++;
		while (i < strlen(body) && body[i] != '+' && body[i] != '-')
			i++;
		int result = parse_and_add_term(body, begin_term, i, ptr_poly);
		if (result == 0) {
			destroy_polynomial(ptr_poly);
			return NULL;
		}
		begin_term = i;
	}
	return ptr_poly;
}

void handle_definition(char* expression) {
	erase_blanks(expression); // 모든 공백 문자들을 제거

	char* f_name = strtok(expression, "=");
	if (f_name == NULL || strlen(f_name) != 1) {
		printf("Unsupported command.");
		return;
	}

	char* exp_body = strtok(NULL, "=");
	if (exp_body == NULL || strlen(exp_body) <= 0) {
		printf("Invalid expression format. --");
		return;
	}

// h= f+g 꼴 정의
	if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x') {
		char* former = strtok(exp_body, "+");
		if (former == NULL || strlen(former) != 1) {
			printf("Invalid expression format.");
			return;
		}

		char* later = strtok(NULL, "+");
		if (later == NULL || strlen(later) != 1) {
			printf("Invalid expression format.");
			return;
		}

		Polynomial* pol = create_by_add_two_polynomias(f_name[0], former[0], later[0]);
	
		if (pol == NULL) {
			printf("Invalid expression format.");
			return;
	}
		insert_polynomial(pol);
	}
	else {
		Polynomial* pol = create_by_parse_polynomial(f_name[0], exp_body);
		if (pol == NULL) {
			printf("Invalid expression format.");
			return;
		}
		insert_polynomial(pol);
	}
}

void process_command() {
	char command_line[BUFFER_LENGTH];
	char copied[BUFFER_LENGTH];
	char* command, * arg1, * arg2;

	while (1) {
		printf("$ ");
		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
			continue;
		strcpy(copied, command_line); // 입력 라인을 복사
		command = strtok(command_line, " ");
		if (strcmp(command, "print") == 0) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			handle_print(arg1[0]); // f, g, h ...
		}
		else if (strcmp(command, "calc") == 0) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			arg2 = strtok(NULL, " ");
			if (arg2 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			handle_calc(arg1[0], arg2);
		}
		else if (strcmp(command, "exit") == 0)
			break;
		else {
			handle_definition(copied); // 다항식을 입력받아 정의
		}
	}
}


