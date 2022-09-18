# include <stdio.h>

int R, C, arr[40][40], visited[40][40], sum=0, dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};

void dfs(int x, int y, int sum) {
	int i, nx, ny, max=0, vec=0;
	visited[x][y]=1;
	sum+=arr[x][y];
	if(x==R-1&&y==C-1) {
		printf("%d", sum);
		exit(0);
	}
	for(i=0 ; i<4 ; i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||nx>=R||ny<0||ny>=C)
			continue;
		if(visited[nx][ny])
			continue;
		if(arr[nx][ny]>max) {
			max=arr[nx][ny];
			vec=i;
		}
	}
	dfs(x+dx[vec], y+dy[vec], sum);
}

int main(void) {
	int i, j;
	scanf("%d%d", &R, &C);
	for(i=0 ; i<R ; i++)
		for(j=0 ; j<C ; j++)
			scanf("%d", &arr[i][j]);
	dfs(0, 0, 0);
	return 0;
}