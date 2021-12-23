# include <stdio.h>

int main(void) {
	char A[4001], B[4001];
	int dp[4000][4000]={0, }, i, j, max=0;
	scanf("%s%s", A, B);
	for(i=0 ; A[i] ; i++)
		for(j=0 ; B[j] ; j++)
			if(A[i]==B[j]) {
				if(!i||!j)
					dp[i][j]=1;
				else
					dp[i][j]=dp[i-1][j-1]+1;
				if(dp[i][j]>max)
					max=dp[i][j];
			}
	printf("%d", max);
	return 0;
}
