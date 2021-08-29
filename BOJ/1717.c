# include <stdio.h>

int parent[1000001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)parent[b]=a;
	else	parent[a]=b;
}

int main(void) {
	int n, m, c, a, b, i;
	scanf("%d%d", &n, &m);
	for(i=1 ; i<=n ; i++)
		parent[i]=i;
	while(m--) {
		scanf("%d%d%d", &c, &a, &b);
		if(c)
			puts(find(a)==find(b)?"YES":"NO");
		else
			union_set(a, b);
	}
	return 0;
}
