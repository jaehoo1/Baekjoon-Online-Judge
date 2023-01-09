# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a>*b; }

int main(void) {
	int P, N, A[1000], i;
	scanf("%d%d", &P, &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &A[i]);
	qsort(A, N, 4, (int(*)(const void*, const void*))intcmp);
	for(i=0 ; P<200&&i<N ; P+=A[i], i++);
	printf("%d", i);
	return 0;
}