# include <stdio.h>

int N, L[100], J[100], dp[100][100];

int max(int a, int b) { return a>b?a:b; }
int recur(int depth, int health) {
	int case1=0, case2;
	if(depth==N)
		return 0;
	if(dp[depth][health])
		return dp[depth][health];
	if(health-L[depth]>0)
		case1=J[depth]+recur(depth+1, health-L[depth]);
	case2=recur(depth+1, health);
	return dp[depth][health]=max(case1, case2);
}

int main(void) {
	int i;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &L[i]);
	for(i=0 ; i<N ; i++)
		scanf("%d", &J[i]);
	printf("%d", recur(0, 100));
	return 0;
}
