# include <cstdio>

int parent[100001];

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

int main(void) {
	int N, M, u, v, cou=0;
	bool tree[100001]={false, };
	scanf("%d%d", &N, &M);
	for(int i=1 ; i<=N ; i++)
		parent[i]=i;
	while(M--) {
		scanf("%d%d", &u, &v);
		if(find(u)==find(v))
			cou++;
		else
			union_set(u, v);
	}
	for(int i=1 ; i<=N ; i++)
		tree[find(i)]=true;
	for(int i=1 ; i<=N ; i++)
		if(tree[i])
			cou++;
	printf("%d", cou-1);
	return 0;
}
