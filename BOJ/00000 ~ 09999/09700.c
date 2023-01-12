# include <stdio.h>

int	N, dx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dy[8]={0, 1, 1, 1, 0, -1, -1, -1}, nx, ny;
char pixel[40][41];

void dfs(int x, int y) {
	int i, nx, ny;
	pixel[x][y]='0';
	for(i=0 ; i<8 ; i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||nx>=N||ny<0||ny>=N||pixel[nx][ny]!='1')
			continue;
		dfs(nx, ny);
	}
}

int main(void) {
	int i, j, x, cou;
	for(x=1 ; ~scanf("%d", &N) ; x++) {
		cou=0;
		for(i=0 ; i<N ; i++)
			scanf("%s", pixel[i]);
		for(i=0 ; i<N ; i++)
			for(j=0 ; j<N ; j++)
				if(pixel[i][j]=='1') {
					cou++;
					dfs(i, j);
				}
		printf("Case #%d: %d\n", x, cou);
	}
	return 0;
}