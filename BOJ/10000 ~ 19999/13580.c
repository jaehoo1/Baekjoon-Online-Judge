# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a>*b; }

int main(void) {
	int arr[3], i;
	for(i=0 ; i<3 ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, 3, 4, (int(*)(const void*, const void*))intcmp);
	if(arr[0]+arr[1]==arr[2]||arr[0]==arr[1]||arr[1]==arr[2])
		puts("S");
	else
		puts("N");
	return 0;
}
