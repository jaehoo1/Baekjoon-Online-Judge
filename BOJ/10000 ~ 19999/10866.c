# include <stdio.h>
# include <string.h>
# define	SIZE	10001

typedef struct {
	int arr[SIZE], front, rear;
}deque;

void init(deque *d) { d->front=d->rear=0; }
void push_front(deque *d, const int x) {
	d->arr[d->front]=x;
	d->front=(d->front-1+SIZE)%SIZE;
}
void push_back(deque *d, const int x) {
	d->rear=(d->rear+1)%SIZE;
	d->arr[d->rear]=x;
}
int pop_front(deque *d) {
	if(empty(d))return -1;
	d->front=(d->front+1)%SIZE;
	return d->arr[d->front];
}
int pop_back(deque *d) {
	int temp;
	if(empty(d))return -1;
	temp=d->arr[d->rear];
	d->rear=(d->rear-1+SIZE)%SIZE;
	return temp;
}
int size(const deque *d) {
	return (d->rear-d->front+SIZE)%SIZE;
}
int empty(const deque *d) {
	return d->front==d->rear;
}
int front(const deque *d) {
	if(empty(d))return -1;
	return d->arr[(d->front+1)%SIZE];
}
int back(const deque *d) {
	if(empty(d))return -1;
	return d->arr[d->rear];
}

int main(void) {
	int N, X;
	char cmd[11];
	deque d;
	init(&d);
	scanf("%d", &N);
	while(N--) {
		scanf("%s", cmd);
		if(!strcmp(cmd, "push_front")) {
			scanf("%d", &X);
			push_front(&d, X);
		}
		else if(!strcmp(cmd, "push_back")) {
			scanf("%d", &X);
			push_back(&d, X);
		}
		else if(!strcmp(cmd, "pop_front"))
			printf("%d\n", pop_front(&d));
		else if(!strcmp(cmd, "pop_back"))
			printf("%d\n", pop_back(&d));
		else if(!strcmp(cmd, "size"))
			printf("%d\n", size(&d));
		else if(!strcmp(cmd, "empty"))
			printf("%d\n", empty(&d));
		else if(!strcmp(cmd, "front"))
			printf("%d\n", front(&d));
		else if(!strcmp(cmd, "back"))
			printf("%d\n", back(&d));
	}
	return 0;
}
