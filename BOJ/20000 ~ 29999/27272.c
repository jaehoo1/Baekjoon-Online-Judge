# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a<*b; }

int main(void) {
	int arr[4], i;
	for(i=0 ; i<4 ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, 4, 4, (int(*)(const void*, const void*))intcmp);
	printf("%d", arr[0]*arr[1]+arr[2]*arr[3]);
	return 0;
}