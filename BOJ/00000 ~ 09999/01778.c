# include <stdio.h>

int parent[50001];

void init(int n) {
	int i;
	for(i=1 ; i<=n ; i++)
		parent[i]=i;
}
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
	int T=0, n, m, i, j, cou;
	while(scanf("%d%d", &n, &m)) {
		if(!n&&!m)
			break;
		init(n);
		while(m--) {
			scanf("%d%d", &i, &j);
			if(find(i)!=find(j))
				union_set(i, j);
		}
		cou=0;
		for(i=1 ; i<=n ; i++)
			if(find(i)==i)
				cou++;
		printf("Case %d: %d\n", ++T, cou);
	}
	return 0;
}