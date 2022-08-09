# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a>*b; }

int main(void) {
	int N, S, arr[20000], i, j, cou=0;
	scanf("%d%d", &N, &S);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	for(i=0 ; i<N-1 ; i++)
		for(j=i+1 ; j<N&&arr[i]+arr[j]<=S ; j++)
			cou++;
	printf("%d", cou);
	return 0;
}