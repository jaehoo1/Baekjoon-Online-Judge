# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a<*b; }

int main(void) {
	int N, k, arr[1000], i;
	scanf("%d%d", &N, &k);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	printf("%d", arr[k-1]);
	return 0;
}