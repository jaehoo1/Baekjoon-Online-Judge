# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a>*b; }

int main(void) {
	int T, C, arr[100], i, time=0;
	scanf("%d%d", &T, &C);
	for(i=0 ; i<C ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, C, 4, (int(*)(const void*, const void*))intcmp);
	for(i=0 ; i<C&&time+arr[i]<=T ; i++)
		time+=arr[i];
	printf("%d", i);
	return 0;
}
