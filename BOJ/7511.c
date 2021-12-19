# include <stdio.h>

int parent[1000000];

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
	int T, t, n, k, m, a, b, u, v, i;
	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		scanf("%d", &n);
		for(i=0 ; i<n ; i++)
			parent[i]=i;
		scanf("%d", &k);
		while(k--) {
			scanf("%d%d", &a, &b);
			union_set(a, b);
		}
		scanf("%d", &m);
		printf("Scenario %d:\n", t);
		while(m--) {
			scanf("%d%d", &u, &v);
			puts(find(u)==find(v)?"1":"0");
		}
		puts("");
	}
	return 0;
}
