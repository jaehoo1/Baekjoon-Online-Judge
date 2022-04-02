# include <stdio.h>

int parent[1000001], size[1000001];

int find(int x) {
	if(x==parent[x])
		return x;
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
	char c;
	int N, a, b, i;
	for(i=1 ; i<=1000000 ; i++) {
		parent[i]=i;
		size[i]=1;
	}
	scanf("%d", &N);
	getchar();
	while(N--) {
		scanf("%c", &c);
		getchar();
		if(c=='I') {
			scanf("%d%d", &a, &b);
			if(find(a)!=find(b))
				union_set(a, b);
		} else if(c=='Q') {
			scanf("%d", &a);
			printf("%d\n", size[find(a)]);
		}
		getchar();
	}
	return 0;
}
