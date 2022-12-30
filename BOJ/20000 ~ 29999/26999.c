# include <stdio.h>

int W, H, max, pixel, dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1}, nx, ny;
char photo[1000][81];

void dfs(int x, int y) {
	int i;
	photo[x][y]='.';
	pixel++;
	for(i=0 ; i<4 ; i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||nx>=H||ny<0||ny>=W||photo[nx][ny]!='*')
			continue;
		dfs(nx, ny);
	}
}

int main(void) {
	int i, j;
	scanf("%d%d", &W, &H);
	for(i=0 ; i<H ; i++)
		scanf("%s", photo[i]);
	for(i=0 ; i<H ; i++)
		for(j=0 ; j<W ; j++)
			if(photo[i][j]=='*') {
				pixel=0;
				dfs(i, j);
				if(pixel>max)
					max=pixel;
			}
	printf("%d", max);
	return 0;
}