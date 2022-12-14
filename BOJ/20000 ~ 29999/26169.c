# include <stdio.h>
# include <stdbool.h>

bool flag, visited[5][5];
int arr[5][5], dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};

void dfs(int x, int y, int depth, int apple) {
	int i, nx, ny;
	if(apple>=2) {
		flag=true;
		return;
	}
	if(depth>=3)
		return;
	visited[x][y]=true;
	for(i=0 ; i<4 ; i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=5||ny<0||ny>=5||arr[nx][ny]==-1||visited[nx][ny])
			continue;
		dfs(nx, ny, depth+1, arr[nx][ny]==1?apple+1:apple);
	}
	visited[x][y]=false;
}

int main(void) {
	int r, c, i, j;
	for(i=0 ; i<5 ; i++)
		for(j=0 ; j<5 ; j++)
			scanf("%d", &arr[i][j]);
	scanf("%d%d", &r, &c);
	dfs(r, c, 0, 0);
	printf("%d", flag);
	return 0;
}