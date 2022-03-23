# include <stdio.h>

int n, dp[500][500], arr[500][500], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1}, nx, ny, res;

int max(int a, int b) { return a>b?a:b; }
int dfs(int x, int y) {
	int i;
	if(dp[x][y])
		return dp[x][y];
	dp[x][y]=1;
	for(i=0 ; i<4 ; i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=n)
			continue;
		if(arr[nx][ny]>arr[x][y])
			dp[x][y]=max(dp[x][y], dfs(nx, ny)+1);
	}
	return dp[x][y];
}

int main(void) {
	int i, j;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			scanf("%d", &arr[i][j]);
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			if(dfs(i, j)>res)
				res=dfs(i, j);
	printf("%d", res);
	return 0;
}
