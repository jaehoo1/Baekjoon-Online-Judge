# include <stdio.h>

int parent[30000], size[30000];

void init(int n) {
	int i;
	for(i=0 ; i<n ; i++) {
		parent[i]=i;
		size[i]=1;
	}
}
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
	int n, m, i, k, set[30000];
	while(scanf("%d%d", &n, &m)) {
		if(!n&&!m)
			break;
		init(n);
		while(m--) {
			scanf("%d", &k);
			for(i=0 ; i<k ; i++)
				scanf("%d", &set[i]);
			if(k>1)
				for(i=1 ; i<k ; i++)
					if(find(set[0])!=find(set[i]))
						union_set(set[0], set[i]);
		}
		printf("%d\n", size[0]);
	}
	return 0;
}