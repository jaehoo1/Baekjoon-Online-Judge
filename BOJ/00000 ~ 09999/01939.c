# include <stdio.h>
# include <stdlib.h>

typedef struct { int A, B, C; }edge;

int parent[10001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)
		parent[b]=a;
	else
		parent[a]=b;
}
int edgecmp(const edge *a, const edge *b) { return a->C<b->C; }

int main(void) {
	int N, M, A, B, i, res;
	edge arr[100000];
	scanf("%d%d", &N, &M);
	for(i=0 ; i<M ; i++)
		scanf("%d%d%d", &arr[i].A, &arr[i].B, &arr[i].C);
	qsort(arr, M, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	scanf("%d%d", &A, &B);
	for(i=0 ; find(A)!=find(B) ; i++) {
		union_set(arr[i].A, arr[i].B);
		res=arr[i].C;
	}
	printf("%d", res);
	return 0;
}
