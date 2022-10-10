# include <stdio.h>

int main(void) {
	int n, A[1000], i, j, cou;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
		scanf("%d", &A[i]);
	for(i=0 ; i<n ; i++) {
		cou=0;
		for(j=0 ; j<i ; j++)
			if(A[j]<A[i])
				cou++;
		printf("%d\n", cou);
	}
	return 0;
}