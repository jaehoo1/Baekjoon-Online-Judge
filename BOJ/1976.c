# include <stdio.h>

int parent[201];

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
	int N, M, num, i, j, arr[1000], flag=1;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		parent[i]=i;
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++) {
			scanf("%d", &num);
			if(num)
				union_set(i, j);
		}
	for(i=0 ; i<M ; i++) {
		scanf("%d", &arr[i]);
		if(i>0)
			if(find(arr[i-1])!=find(arr[i])) {
				flag=0;
				break;
			}
	}
	puts(flag?"YES":"NO");
	return 0;
}
