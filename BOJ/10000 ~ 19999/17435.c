# include <stdio.h>
# define	MAX_EXP	19

int main(void) {
    int m, arr[200001][MAX_EXP], i, j, Q, n, x;
	scanf("%d", &m);
	for(i=1 ; i<=m ; i++)
		scanf("%d", &arr[i][0]);
	for(j=1 ; j<MAX_EXP ; j++)
		for(i=1 ; i<=m ; i++)
			arr[i][j]=arr[arr[i][j-1]][j-1];
	scanf("%d", &Q);
	while(Q--) {
		scanf("%d%d", &n, &x);
		for(i=MAX_EXP-1 ; i>=0 ; i--)
			if(n>=1<<i) {
				n-=1<<i;
				x=arr[x][i];
			}
		printf("%d\n", x);
	}
	return 0;
}