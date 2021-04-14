#include <stdio.h>
#include <string.h>
#define SIZE 100

//덱 구조체 정의
typedef char element;
typedef struct {
	element data[SIZE];
	int front,rear;
}DequeType;

//초기화 함수
void init_deque(DequeType *d) {
	d->front = d->rear = 0;
}

//삽입 함수
void add_rear(DequeType *d, element a) {
	d->rear = (d->rear + 1) % SIZE;
	d->data[d->rear] = a;
}

void add_front(DequeType *d, element a) {
	d->data[d->front] = a;
	d->front = (d->front - 1 + SIZE) % SIZE;
}
//삭제 함수
element delete_front(DequeType *d) {
	d->front = (d->front + 1)%SIZE;
	return d->data[(d->front)];
}

element delete_rear(DequeType *d) {
	int prev = d->rear;
	d->rear = (d->rear - 1 + SIZE) % SIZE;
	return d->data[prev];
}

int main() {
	element s[SIZE];
	DequeType d1;
	init_deque(&d1);
	scanf("%s", s);

	int len = strlen(s);
	element c[len];

	for(int i=0;i<len;i++)
		add_rear(&d1, s[i]);

	for(int i=0;i<len;i++)
		c[i] = delete_rear(&d1);


	element b[len];
	for(int i=0;i<len;i++)
		add_rear(&d1, s[i]);

	for(int i=0;i<len;i++)
		b[i] = delete_front(&d1);

	if(strcmp(c,b)==0)
		printf("%s는 회문입니다.", b);
	else
		printf("%s는 회문이 아닙니다.", b);

	return 0;

}
