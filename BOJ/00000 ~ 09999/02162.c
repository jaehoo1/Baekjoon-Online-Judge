# include <stdio.h>

typedef struct {
	int x, y;
}pos;
typedef struct {
	pos A, B;
}line;

int parent[3000];

int find(int x) {
	if(parent[x]<0)return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(parent[a]>parent[b]) {
		parent[b]+=parent[a];
		parent[a]=b;
	}
	else {
		parent[a]+=parent[b];
		parent[b]=a;
	}
}
int ccw(pos A, pos B, pos C) {
	int a=A.x*B.y+B.x*C.y+C.x*A.y, b=B.x*A.y+C.x*B.y+A.x*C.y;
	if(a-b>0)return 1;
	else if(a-b<0)return -1;
	return 0;
}
int islined(pos A, pos B, pos C) {
	if(A.x<B.x)
		return B.x<C.x;
	else if(B.x<A.x)
		return C.x<B.x;
	if(A.y<B.y)
		return B.y<C.y;
	else if(B.y<A.y)
		return C.y<B.y;
}
int isgroup(line a, line b) {
	if(ccw(a.A, a.B, b.A)*ccw(a.A, a.B, b.B)==0&&ccw(b.A, b.B, a.A)*ccw(b.A, b.B, a.B)==0)
		if((islined(a.A, a.B, b.A)&&islined(a.A, a.B, b.B))||(islined(a.B, a.A, b.A)&&islined(a.B, a.A, b.B)))
			return 0;
		else
			return 1;
	else if(ccw(a.A, a.B, b.A)*ccw(a.A, a.B, b.B)<=0&&ccw(b.A, b.B, a.A)*ccw(b.A, b.B, a.B)<=0)
		return 1;
	else
		return 0;
}
int iscycle(int a, int b) {
	a=find(a);
	b=find(b);
	if(a==b)return 1;
	return 0;
}

int main(void) {
	line arr[3000];
	int N, i, j, cou=0, min=3000;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		parent[i]=-1;
		scanf("%d%d%d%d", &arr[i].A.x, &arr[i].A.y, &arr[i].B.x, &arr[i].B.y);
	}
	for(i=0 ; i<N-1 ; i++)
		for(j=i+1 ; j<N ; j++)
			if(isgroup(arr[i], arr[j])&&!iscycle(i, j))
				union_set(i, j);
	for(i=0 ; i<N ; i++) {
		if(parent[i]<0)
			cou++;
		if(parent[i]<min)
			min=parent[i];
	}
	printf("%d\n%d", cou, -min);
	return 0;
}
