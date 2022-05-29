# include <stdio.h>

int parent[300001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)parent[b]=parent[a];
	else	parent[a]=parent[b];
}

int main(void) {
	int N, i, a, b;
	scanf("%d", &N);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	for(i=0 ; i<N-2 ; i++) {
		scanf("%d%d", &a, &b);
		union_set(a, b);
	}
	for(i=1 ; i<=N ; i++)
		if(find(i)==i)
			printf("%d ", i);
	return 0;
}
