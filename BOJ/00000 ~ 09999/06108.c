# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a>*b; }

int main(void) {
	int N, i, j, arr[99], res[99];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<N ; j++)
			scanf("%d", &arr[j]);
		qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
		res[i]=arr[N/2];
	}
	qsort(res, N, 4, (int(*)(const void*, const void*))intcmp);
	printf("%d", res[N/2]);
	return 0;
}