# include <stdio.h>
# include <stdlib.h>

typedef struct { int s, d, c; }edge;

int parent[26];

int find(int x) {
	if(parent[x]==x)
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
int edgecmp(const edge *a, const edge *b) {
	if(a->c<b->c)
		return -1;
	else if(a->c>b->c)
		return 1;
	else
		return 0;
}

int main(void) {
	int n, k, cst, i, ptr, sum;
	char src, dst;
	edge arr[400];
	while(scanf("%d", &n)) {
		getchar();
		if(!n)
			break;
		n--;
		ptr=0;
		sum=0;
		for(i=0 ; i<26 ; i++)
			parent[i]=i;
		while(n--) {
			scanf("%c", &src);
			getchar();
			scanf("%d", &k);
			getchar();
			while(k--) {
				scanf("%c", &dst);
				getchar();
				scanf("%d", &cst);
				getchar();
				arr[ptr].s=src-'A';
				arr[ptr].d=dst-'A';
				arr[ptr++].c=cst;
			}
		}
		qsort(arr, ptr, sizeof(edge), edgecmp);
		for(i=0 ; i<ptr ; i++)
			if(find(arr[i].s)!=find(arr[i].d)) {
				union_set(arr[i].s, arr[i].d);
				sum+=arr[i].c;
			}
		printf("%d\n", sum);
	}
	return 0;
}