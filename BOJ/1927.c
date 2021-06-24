# include <stdio.h>

typedef struct {
	int arr[100001], ptr;
}heap;

void init(heap *h) { h->ptr=0; }
void swap(int *a, int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}
void insert(heap *h, const int x) {
	int i=++h->ptr;
	while(i!=1&&x<h->arr[i/2]) {
		h->arr[i]=h->arr[i/2];
		i/=2;
	}
	h->arr[i]=x;
}
int delete(heap *h) {
	int res=h->arr[1], p=1, c;
	if(!h->ptr)return 0;
	h->arr[1]=h->arr[h->ptr--];
	while(1) {
		c=p*2;
		if(c+1<=h->ptr&&h->arr[c]>h->arr[c+1])
			c++;
		if(c>h->ptr||h->arr[c]>h->arr[p])
			break;
		swap(&h->arr[p], &h->arr[c]);
		p=c;
	}
	return res;
}

int main(void) {
	int N, x;
	heap h;
	init(&h);
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &x);
		if(x)insert(&h, x);
		else	printf("%d\n", delete(&h));
	}
	return 0;
}
