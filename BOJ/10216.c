# include <stdio.h>
# include <math.h>

typedef struct { int x, y; }pos;
typedef struct {
	pos p;
	int r;
}circle;

int parent[3001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)parent[b]=parent[a];
	else	parent[a]=parent[b];
}
double dist(circle a, circle b) {
	return sqrt((double)(a.p.x-b.p.x)*(a.p.x-b.p.x)+(a.p.y-b.p.y)*(a.p.y-b.p.y));
}

int main(void) {
	int T, N, i, j, cou;
	circle arr[3001];
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(i=1 ; i<=N ; i++) {
			parent[i]=i;
			scanf("%d%d%d", &arr[i].p.x, &arr[i].p.y, &arr[i].r);
		}
		for(i=1 ; i<=N-1 ; i++)
			for(j=i+1 ; j<=N ; j++)
				if(dist(arr[i], arr[j])<=arr[i].r+arr[j].r)
					union_set(i, j);
		cou=0;
		for(i=1 ; i<=N ; i++)
			if(find(i)==i)
				cou++;
		printf("%d\n", cou);
	}
	return 0;
}
