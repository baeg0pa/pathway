#include <stdio.h>
#include <stdlib.h>
typedef int element;

//스택 구조체
typedef struct {
	element data[5];
	int top;
}StackType;

//초기화
void init_stack(StackType* s) {
	s->top = -1;
}

//에러 출력 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//포화상태(스택)
int is_full(StackType* s) {
	return s->top == 4;
}

//공백상태(스택)
int is_empty(StackType* s) {
	return s->top == -1;
}

//삽입 함수(스택)
void push(StackType* s, element item) {
	if (is_full(s))
		error("포화상태");
	else
		s->data[(s->top)++] = item;
}

//삭제 함수(스택)
int pop(StackType* s) {
	if(is_empty(s)) {
		error("공백상태");
		return -1;
	}
	else
		return s->data[(s->top)--];
}

// 큐 구조체
typedef struct {
	StackType s1, s2;
}QueueType;

// 초기화
void init_queue(QueueType* q) {
	init_stack(&(q->s1));
	init_stack(&(q->s2));
}


//삽입함수
void enqueue(QueueType* q, int item) {
	push(&(q->s1),item);
}

//삭제함수(큐에서 꺼내는? 함수)
int dequeue(QueueType *q) {
	if(is_empty(&(q->s2))) {
		while(!is_empty(&(q->s1)))
			push(&(q->s2), pop(&(q->s1)));
	}
	return pop(&(q->s2));
}

int main() {
	QueueType q;
	init_queue(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	printf("%d	|	", dequeue(&q));
	printf("%d	|	", dequeue(&q));
	printf("%d	|	", dequeue(&q));

}
