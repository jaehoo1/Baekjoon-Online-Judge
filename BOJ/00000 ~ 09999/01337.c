# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a>*b; }

int main(void) {
	int N, arr[50], i, j, max=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	for(i=0 ; i<N ; i++) {
		for(j=i+1 ; j<i+5&&j<N&&arr[j]<=arr[i]+4 ; j++);
		if(j-i>max)
			max=j-i;
	}
	printf("%d", 5-max);
	return 0;
}
