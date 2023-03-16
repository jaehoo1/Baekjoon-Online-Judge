# include <stdio.h>
# include <stdbool.h>

bool visited[40][40];
int H, W, dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1}, cou;
char tile[40][41];

void dfs(int x, int y) {
	int i, nx, ny;
	visited[x][y]=true;
	cou++;
	for(i=0 ; i<4 ; i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||nx>=H||ny<0||ny>=W||visited[nx][ny]||tile[nx][ny]!='.')
			continue;
		dfs(nx, ny);
	}
}


int main(void) {
	int i, j, sx, sy;
	while(scanf("%d%d", &W, &H)) {
		if(!W&&!H)
			break;
		cou=0;
		for(i=0 ; i<H ; i++)
			for(j=0 ; j<W ; j++)
				visited[i][j]=false;
		for(i=0 ; i<H ; i++) {
			scanf("%s", tile[i]);
			for(j=0 ; j<W ; j++)
				if(tile[i][j]=='A') {
					sx=i;
					sy=j;
				}
		}
		dfs(sx, sy);
		printf("%d\n", cou);
	}
	return 0;
}