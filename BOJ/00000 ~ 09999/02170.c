# include <stdio.h>
# include <stdlib.h>

typedef struct { int x, y; }pos;

int poscmp(const pos *a, const pos *b) {
	if(a->x<b->x)return -1;
	else if(a->x>b->x)return 1;
	else
		if(a->y<b->y)return -1;
		else if(a->y>b->y)return 1;
		else	return 0;
}

int main(void) {
	int N, i, res=0;
	pos arr[1000000], cur;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d%d", &arr[i].x, &arr[i].y);
	qsort(arr, N, sizeof(pos), (int(*)(const void*, const void*))poscmp);
	cur=arr[0];
	for(i=1 ; i<N ; i++)
		if(cur.y>=arr[i].x)
			cur.y=cur.y>arr[i].y?cur.y:arr[i].y;
		else {
			res+=cur.y-cur.x;
			cur=arr[i];
		}
	res+=cur.y-cur.x;
	printf("%d", res);
	return 0;
}
