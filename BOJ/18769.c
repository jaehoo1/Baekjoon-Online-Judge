# include <stdio.h>
# include <stdlib.h>

typedef struct { int a, b, c; }edge;

int parent[250000];

int find(int x) {
	if(x==parent[x])
		return x;
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
int edgecmp(const edge *a, const edge *b) { return a->c>b->c; }

int main(void) {
	int T, R, C, i, j, ptr, cost, sum;
	edge arr[500000];
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &R, &C);
		for(i=0 ; i<R ; i++)
			for(j=0 ; j<C ; j++)
				parent[i*C+j]=i*C+j;
		ptr=0;
		for(i=0 ; i<R ; i++)
			for(j=0 ; j<C-1 ; j++) {
				scanf("%d", &cost);
				arr[ptr].a=i*C+j;
				arr[ptr].b=arr[ptr].a+1;
				arr[ptr++].c=cost;
			}
		for(i=0 ; i<R-1 ; i++)
			for(j=0 ; j<C ; j++) {
				scanf("%d", &cost);
				arr[ptr].a=i*C+j;
				arr[ptr].b=arr[ptr].a+C;
				arr[ptr++].c=cost;
			}
		qsort(arr, ptr, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
		sum=0;
		for(i=0 ; i<ptr ; i++)
			if(find(arr[i].a)!=find(arr[i].b)) {
				union_set(arr[i].a, arr[i].b);
				sum+=arr[i].c;
			}
		printf("%d\n", sum);
	}
	return 0;
}
