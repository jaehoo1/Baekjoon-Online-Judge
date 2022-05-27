# include <stdio.h>

int parent[1001];

int find(int x) {
	if(x==parent[x])
		return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a==b)
		return;
	if(a<b)
		parent[b]=a;
	else
		parent[a]=b;
}

int main(void) {
	int N, M, Q, X, Y, i;
	scanf("%d%d%d", &N, &M, &Q);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	while(M--) {
		scanf("%d%d", &X, &Y);
		union_set(X, Y);
	}
	while(Q--) {
		scanf("%d%d", &X, &Y);
		puts(find(X)==find(Y)?"Y":"N");
	}
	return 0;
}
