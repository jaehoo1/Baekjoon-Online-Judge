# include <stdio.h>

char map[600][601];
int N, M, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1}, res, visited[600][600];

void dfs(int x, int y) {
	int i, nx, ny;
	visited[x][y]=1;
	if(map[x][y]=='P')
		res++;
	for(i=0 ; i<4 ; i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||nx>=N||ny<0||ny>=M)
			continue;
		if(visited[nx][ny]||map[nx][ny]=='X')
			continue;
		dfs(nx, ny);
	}
}

int main(void) {
	int i, j, sx=-1, sy=-1;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++) {
		scanf("%s", map[i]);
		if(sx==-1)
			for(j=0 ; j<M ; j++)
				if(map[i][j]=='I') {
					sx=i;
					sy=j;
					break;
				}
	}
	dfs(sx, sy);
	if(res)
		printf("%d", res);
	else
		puts("TT");
	return 0;
}
