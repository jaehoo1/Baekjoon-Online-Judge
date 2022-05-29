# include <stdio.h>
# include <math.h>

typedef struct { int x, y; }pos;

int main(void) {
	int N, i, sum=0;
	pos arr[20];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d%d", &arr[i].x, &arr[i].y);
	for(i=1 ; i<N ; i++)
		sum+=abs(arr[i-1].x-arr[i].x)+abs(arr[i-1].y-arr[i].y);
	sum+=abs(arr[0].x-arr[N-1].x)+abs(arr[0].y-arr[N-1].y);
	printf("%d", sum);
	return 0;
}
