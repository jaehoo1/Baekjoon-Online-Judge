# include <stdio.h>
# include <stdbool.h>

bool visited[100][100];
int n, dx[2]={0, 1}, dy[2]={1, 0};
char arr[100][101];

void dfs(int x, int y) {
	int i, nx, ny;
	visited[x][y]=true;
	if(x==n-1&&y==n-1) {
		puts("Yes");
		exit(0);
	}
	for(i=0 ; i<2 ; i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=n||ny>=n||arr[nx][ny]=='x'||visited[nx][ny])
			continue;
		dfs(nx, ny);
	}
}

int main(void) {
	int i;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
		scanf("%s", arr[i]);
	dfs(0, 0);
	puts("No");
	return 0;
}