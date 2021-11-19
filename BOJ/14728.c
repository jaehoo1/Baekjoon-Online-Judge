# include <stdio.h>

int N, T, K[100], S[100], dp[101][10001];

int max(int a, int b) { return a>b?a:b; }
int recur(int depth, int time) {
	int case1=0, case2;
	if(depth==N)
		return 0;
	if(dp[depth][time])
		return dp[depth][time];
	if(time+K[depth]<=T)
		case1=recur(depth+1, time+K[depth])+S[depth];
	case2=recur(depth+1, time);
	return dp[depth][time]=max(case1, case2);
}

int main(void) {
	int i;
	scanf("%d%d", &N, &T);
	for(i=0 ; i<N ; i++)
		scanf("%d%d", &K[i], &S[i]);
	printf("%d", recur(0, 0));
	return 0;
}
