# include <stdio.h>

int parent[500000];

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
	int n, m, i, a, b, cycle=0;
	scanf("%d%d", &n, &m);
	for(i=0 ; i<n ; i++)
		parent[i]=i;
	for(i=0 ; i<m ; i++) {
		scanf("%d%d", &a, &b);
		if(find(a)==find(b)) {
			cycle=i+1;
			break;
		}
		union_set(a, b);
	}
	printf("%d", cycle);
	return 0;
}
