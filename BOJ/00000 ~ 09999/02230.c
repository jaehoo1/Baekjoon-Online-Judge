# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int intcmp(const int *a, const int *b) {
	if(*a<*b)return -1;
	else if(*a>*b)return 1;
	else	return 0;
}

int main(void) {
	int N, M, arr[100000], i, start=0, end=0, min=2000000000, dist;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	while(start!=N) {
		dist=abs(arr[start]-arr[end]);
		if(dist<M&&end<N-1)
			end++;
		else
			start++;
		if(dist>=M)
			if(dist<min)
				min=dist;
	}
	printf("%d", min);
	return 0;
}
