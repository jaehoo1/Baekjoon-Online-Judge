# include <stdio.h>

typedef struct { int x, y; }pos;

int parent[500];

int dist(const pos *a, const pos *b) { return (a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y); }
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
	int n, i, j, s=0, c, min, temp;
	pos arr[500];
	while(scanf("%d", &n)) {
		if(!n)
			break;
		for(i=0 ; i<n ; i++) {
			parent[i]=i;
			scanf("%d%d", &arr[i].x, &arr[i].y);
		}
		for(i=0 ; i<n ; i++) {
			min=1000001;
			for(j=0 ; j<n ; j++) {
				if(i==j)
					continue;
				temp=dist(&arr[i], &arr[j]);
				if(temp<min)
					min=temp;
			}
			for(j=0 ; j<n ; j++)
				if(find(i)!=find(j)&&min==dist(&arr[i], &arr[j]))
					union_set(i, j);
		}
		c=0;
		for(i=0 ; i<n ; i++)
			if(find(i)==i)
				c++;
		printf("Sky %d contains %d constellations.\n", ++s, c);
	}
	return 0;
}