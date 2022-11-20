# include <stdio.h>
# include <stdlib.h>

typedef struct { int b, p, q, r, mul, sum; }climber;

void init(climber *c) {
	scanf("%d%d%d%d", &c->b, &c->p, &c->q, &c->r);
	c->mul=c->p*c->q*c->r;
	c->sum=c->p+c->q+c->r;
}
int cmp(const climber *a, const climber *b) {
	if(a->mul<b->mul)
		return -1;
	else if(a->mul>b->mul)
		return 1;
	else
		if(a->sum<b->sum)
			return -1;
		else if(a->sum>b->sum)
			return 1;
		else
			if(a->b<b->b)
				return -1;
			else if(a->b>b->b)
				return 1;
			else
				return 0;
}

int main(void) {
	int n, i;
	climber arr[100];
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
		init(&arr[i]);
	qsort(arr, n, sizeof(climber), (int(*)(const void*, const void*))cmp);
	for(i=0 ; i<3 ; i++)
		printf("%d ", arr[i].b);
	return 0;
}