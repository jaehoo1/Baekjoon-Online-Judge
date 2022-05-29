# include <stdio.h>

int N, M, arr[500][500], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1}, dp[500][500], visited[500][500];

int recur(int curx, int cury) {
	int x, y, i, route=0;
	if(curx==N-1&&cury==M-1)
		return 1;
	if(visited[curx][cury])
		return dp[curx][cury];
	for(i=0 ; i<4 ; i++) {
		x=curx+dx[i];
		y=cury+dy[i];
		if(x<0||x>=N||y<0||y>=M)
			continue;
		if(arr[x][y]<arr[curx][cury])
			route+=recur(x, y);
	}
	visited[curx][cury]=1;
	return dp[curx][cury]=route;
}

int main(void) {
	int i, j;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			scanf("%d", &arr[i][j]);
	printf("%d", recur(0, 0));
	return 0;
}
