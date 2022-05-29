# include <stdio.h>

typedef enum {
	false, true
}bool;

int main(void) {
	int N, M, a, b, cou=0, i, j, k, temp;
	bool dp[501][501]={0, };
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &a, &b);
		dp[a][b]=1;
	}
	for(k=1 ; k<=N ; k++)
		for(i=1 ; i<=N ; i++)
			for(j=1 ; j<=N ; j++)
				if(dp[i][k]&&dp[k][j])
					dp[i][j]=1;
	for(i=1 ; i<=N ; i++) {
		temp=0;
		for(j=1 ; j<=N ; j++) {
			if(dp[i][j])temp++;
			if(dp[j][i])temp++;
		}
		if(temp==N-1)cou++;
	}
	printf("%d", cou);
	return 0;
}
