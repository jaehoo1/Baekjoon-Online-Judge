# include <stdio.h>

int N, K, importance[1000], studytime[1000], dp[10000][1000];

int max(int a, int b) { return a>b?a:b; }
int recur(int depth, int time) {
	int case1=0, case2;
	if(dp[time][depth])
		return dp[time][depth];
	if(depth==K)
		return 0;
	if(time+studytime[depth]<=N)
		case1=importance[depth]+recur(depth+1, time+studytime[depth]);
	case2=recur(depth+1, time);
	return dp[time][depth]=max(case1, case2);
}

int main(void) {
	int i;
	scanf("%d%d", &N, &K);
	for(i=0 ; i<K ; i++)
		scanf("%d%d", &importance[i], &studytime[i]);
	printf("%d", recur(0, 0));
	return 0;
}