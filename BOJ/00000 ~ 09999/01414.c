# include <stdio.h>
# include <stdlib.h>

typedef struct { int s, d, c; }edge;

int parent[50];

int edgecmp(const edge *a, const edge *b) {
	if(a->c<b->c)
		return -1;
	else if(a->c>b->c)
		return 1;
	else
		return 0;
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
	int N, i, j, ptr=0, cost=0, cou=0, sum=0, len;
	char str[50][51];
	edge arr[2500];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%s", str[i]);
		parent[i]=i;
	}
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++) {
			if(str[i][j]=='0')
				len=0;
			else if(str[i][j]>='a'&&str[i][j]<='z')
				len=str[i][j]-'a'+1;
			else if(str[i][j]>='A'&&str[i][j]<='Z')
				len=str[i][j]-'A'+27;
			sum+=len;
			if(i!=j&&len) {
				arr[ptr].s=i;
				arr[ptr].d=j;
				arr[ptr++].c=len;
			}
		}
	qsort(arr, ptr, sizeof(edge), (int(*)(const void*, const void*))edgecmp);
	for(i=0 ; i<ptr ; i++) {
		if(find(arr[i].s)!=find(arr[i].d)) {
			cou++;
			cost+=arr[i].c;
			union_set(arr[i].s, arr[i].d);
		}
	}
	printf("%d", cou==N-1?sum-cost:-1);
	return 0;
}