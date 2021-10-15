# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int a, b, c;
}edge;

int parent[100001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)parent[b]=parent[a];
	else	parent[b]=parent[a];
}
int edgecmp(const edge *a, const edge *b) {
	if(a->c<b->c)return -1;
	else if(a->c>b->c)return 1;
	else	return 0;
}

int main(void) {
	int N, M, i, cou=0;
	long long cost=0, sum=0;
	edge arr[500000];
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	for(i=0 ; i<M ; i++) {
		scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c);
		sum+=arr[i].c;
	}
	qsort(arr, M, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=0 ; i<M ; i++)
		if(find(arr[i].a)!=find(arr[i].b)) {
			union_set(arr[i].a, arr[i].b);
			cost+=arr[i].c;
			cou++;
		}
	printf("%lld", cou==N-1?sum-cost:-1);
	return 0;
}
