# include <stdio.h>

int main(void) {
	int n, m, i, j, cou=0;
	char A[100][101], B[100][101];
	scanf("%d%d", &n, &m);
	for(i=0 ; i<n ; i++)
		scanf("%s", A[i]);
	for(i=0 ; i<n ; i++)
		scanf("%s", B[i]);
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<m ; j++)
			if(A[i][j]==B[i][j])
				cou++;
	printf("%d", cou);
	return 0;
}