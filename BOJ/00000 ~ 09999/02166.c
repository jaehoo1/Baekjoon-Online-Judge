# include <stdio.h>

typedef struct { long long x, y; }pos;

long long ccw(pos A, pos B, pos C) {
	long long a=A.x*B.y+B.x*C.y+C.x*A.y, b=B.x*A.y+C.x*B.y+A.x*C.y;
	return a-b;
}
double abs(long long x) { return x<0?-x:x; }

int main(void) {
	int N, i;
	pos arr[10000];
	long long sum=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%lld%lld", &arr[i].x, &arr[i].y);
	for(i=2 ; i<N ; i++)
		sum+=ccw(arr[0], arr[i-1], arr[i]);
	printf("%.1lf", abs(sum)/2);
	return 0;
}
