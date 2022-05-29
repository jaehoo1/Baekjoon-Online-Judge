# include <stdio.h>

int N, M, V[50], dp[51][1001];

int max(int a, int b) { return a>b?a:b; }
int recur(int depth, int volume) {
	int case1=-1, case2=-1;
	if(dp[depth][volume])
		return dp[depth][volume];
	if(depth==N)
		return volume;
	if(volume+V[depth]<=M)
		case1=recur(depth+1, volume+V[depth]);
	if(volume-V[depth]>=0)
		case2=recur(depth+1, volume-V[depth]);
	return dp[depth][volume]=max(case1, case2);
}

int main(void) {
	int S, i;
	scanf("%d%d%d", &N, &S, &M);
	for(i=0 ; i<N ; i++)
		scanf("%d", &V[i]);
	printf("%d", recur(0, S));
	return 0;
}
