# include <stdio.h>
# include <stdlib.h>

typedef struct { int idx, num; }data;

int datacmp(const data *a, const data *b) { return a->idx>b->idx; }

int main(void) {
	int N, i, j, A, B, dp[100]={1}, max;
	data arr[100];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d%d", &A, &B);
		arr[i].idx=A;
		arr[i].num=B;
	}
	qsort(arr, N, sizeof(data), (int(*)(const void*, const void*))datacmp);
	for(i=1 ; i<N ; i++) {
		max=0;
		for(j=0 ; j<i ; j++)
			if(dp[j]>max&&arr[i].num>arr[j].num)
				max=dp[j];
		dp[i]=max+1;
	}
	max=0;
	for(i=0 ; i<N ; i++)
		if(dp[i]>max)
			max=dp[i];
	printf("%d", N-max);
	return 0;
}
