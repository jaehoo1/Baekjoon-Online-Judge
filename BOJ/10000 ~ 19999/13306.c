# include <stdio.h>

typedef struct { int x, a, b; }query;

int parent[200001];

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
	int N, Q, a[200001], i, res[200000], ptr=0;
	query arr[399999];
	scanf("%d%d", &N, &Q);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	for(i=2 ; i<=N ; i++)
		scanf("%d", &a[i]);
	for(i=0 ; i<N-1+Q ; i++) {
		scanf("%d%d", &arr[i].x, &arr[i].a);
		if(arr[i].x)
			scanf("%d", &arr[i].b);
	}
	for(i=N+Q-2 ; i>=0 ; i--)
		if(arr[i].x)
			res[ptr++]=find(arr[i].a)==find(arr[i].b);
		else
			union_set(arr[i].a, a[arr[i].a]);
	for(i=ptr-1 ; i>=0 ; i--)
		puts(res[i]?"YES":"NO");
	return 0;
}