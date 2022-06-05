# include <stdio.h>

int parent[100001];

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

int main(void) {
	int N, M, i, j, A, pre, cou=0;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	while(M--) {
		scanf("%d%d", &i, &j);
		union_set(i, j);
	}
	scanf("%d", &A);
	pre=find(A);
	for(i=1 ; i<N ; i++) {
		scanf("%d", &A);
		if(find(A)!=pre)
			cou++;
		pre=find(A);
	}
	printf("%d", cou);
	return 0;
}