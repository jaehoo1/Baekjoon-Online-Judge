# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a>*b; }
int max(int a, int b) { return a>b?a:b; }

int main(void) {
	int N, K, arr[1000], i, res=0, ptr=0;
	scanf("%d%d", &N, &K);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, intcmp);
	for(i=0 ; i<N ; i++) {
		if(arr[i]-arr[ptr]>K)
			ptr++;
		res=max(res, i-ptr+1);
	}
	printf("%d", res);
	return 0;
}