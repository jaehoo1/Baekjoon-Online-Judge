# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a<*b; }

int main(void) {
	int N, arr[100000], i, max=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	for(i=0 ; i<N ; i++)
		if(arr[i]*(i+1)>max)
			max=arr[i]*(i+1);
	printf("%d", max);
	return 0;
}
