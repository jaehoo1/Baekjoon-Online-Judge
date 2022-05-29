# include <stdio.h>

int parent[100001], size[100001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b) {
		size[a]+=size[b];
		parent[b]=a;
	} else {
		size[b]+=size[a];
		parent[a]=b;
	}
}

int main(void) {
	int N, M, a, b, i;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++) {
		parent[i]=i;
		scanf("%d", &size[i]);
	}
	while(M--) {
		scanf("%d%d", &a, &b);
		if(find(a)!=find(b))
			union_set(a, b);
		printf("%d\n", size[find(a)]);
	}
	return 0;
}
