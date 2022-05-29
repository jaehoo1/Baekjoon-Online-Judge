# include <stdio.h>

typedef struct {
	int arr[100000], front, rear, vec;
}deque;

void init(deque *d, const int N) {
	int i;
	d->vec=0;
	d->front=0;
	d->rear=N;
	getchar();
	if(N==0) {
		scanf("[]");
		return;
	}
	else if(N==1) {
		scanf("[%d]", &d->arr[0]);
		return;
	}
	scanf("[%d,", &d->arr[0]);
	for(i=1 ; i<N-1 ; i++)
		scanf("%d,", &d->arr[i]);
	scanf("%d]", &d->arr[N-1]);
}
int isempty(const deque *d) { return d->front==d->rear; }
int pop_front(deque *d) { 
	if(isempty(d))
		return -1;
	d->front++;
	return 1;
}
int pop_rear(deque *d) {
	if(isempty(d))
		return -1;
	d->rear--;
	return 1;
}
void reverse(deque *d) {
	if(d->vec)d->vec=0;
	else	d->vec=1;
}
void printd(deque *d) {
	int i;
	printf("[");
	if(!isempty(d))
		if(d->vec) {
			for(i=d->rear-1 ; i!=d->front ; i--)
				printf("%d,", d->arr[i]);
			printf("%d", d->arr[d->front]);
		}
		else {
			for(i=d->front ; i<d->rear-1 ; i++)
				printf("%d,", d->arr[i]);
			printf("%d", d->arr[d->rear-1]);
		}
	printf("]\n");
}

int main(void) {
	deque d;
	int T, i, n, err;
	char p[100001];
	scanf("%d", &T);
	while(T--) {
		err=0;
		scanf("%s%d", p, &n);
		init(&d, n);
		for(i=0 ; p[i] ; i++)
			if(p[i]=='R')
				reverse(&d);
			else if(p[i]=='D') {
				if(d.vec)err=pop_rear(&d);
				else	err=pop_front(&d);
				if(err==-1)break;
			}
		if(err==-1)puts("error");
		else	printd(&d);
	}
	return 0;
}
