# include <stdio.h>

int N, K, W[101], V[101], res[101], dp[101][100001];

int max(int a, int b) { return a>b?a:b; }
int recur(int depth, int weight) {
	int case1=0, case2;
	if(dp[depth][weight])
		return dp[depth][weight];
	if(depth==N)
		return 0;
	if(weight+W[depth]<=K)
		case1=V[depth]+recur(depth+1, weight+W[depth]);
	case2=recur(depth+1, weight);
	return dp[depth][weight]=max(case1, case2);
}

int main(void) {
	int i;
	scanf("%d%d", &N, &K);
	for(i=0 ; i<N ; i++)
		scanf("%d%d", &W[i], &V[i]);
	printf("%d", recur(0, 0));
	return 0;
}
