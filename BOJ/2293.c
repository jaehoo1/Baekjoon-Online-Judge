# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) { return *a>*b; }

int main(void) {
	int dp[100001]={0, }, coin[100], n, k, i, j;
	scanf("%d%d", &n, &k);
	for(i=0 ; i<n ; i++)
		scanf("%d", &coin[i]);
	qsort(coin, n, 4, (int(*)(const void*, const void*))intcmp);
	for(i=coin[0] ; i<=k ; i+=coin[0])
		dp[i]++;
	for(i=1 ; i<n ; i++) {
		dp[coin[i]]++;
		for(j=coin[i]+1 ; j<=k ; j++)
			dp[j]+=dp[j-coin[i]];
	}
	printf("%d", dp[k]);
	return 0;
}
