# include <stdio.h>

int R, C, map[1000][1000];

void dfs(int x, int y) {
	map[x][y]=0;
	if(x)if(map[x-1][y])dfs(x-1, y);
	if(x<R-1)if(map[x+1][y])dfs(x+1, y);
	if(y)if(map[x][y-1])dfs(x, y-1);
	if(y<C-1)if(map[x][y+1])dfs(x, y+1);
	if(x&&y)if(map[x-1][y-1])dfs(x-1, y-1);
	if(x&&y<C-1)if(map[x-1][y+1])dfs(x-1, y+1);
	if(x<R-1&&y)if(map[x+1][y-1])dfs(x+1, y-1);
	if(x<R-1&&y<C-1)if(map[x+1][y+1])dfs(x+1, y+1);
}

int main(void) {
	int i, j, cou=0;
	scanf("%d%d", &R, &C);
	for(i=0 ; i<R ; i++)
		for(j=0 ; j<C ; j++)
			scanf("%d", &map[i][j]);
	for(i=0 ; i<R ; i++)
		for(j=0 ; j<C ; j++)
			if(map[i][j]) {
				dfs(i, j);
				cou++;
			}
	printf("%d", cou);
	return 0;
}
