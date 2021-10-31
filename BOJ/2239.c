# include <stdio.h>

int board[9][9], visitedrow[9][10], visitedcol[9][10], visitedrc[9][10];

void dfs(int depth) {
	int x=depth/9, y=depth%9, i, j;
	if(depth==81) {
		for(i=0 ; i<9 ; i++) {
			for(j=0 ; j<9 ; j++)
				printf("%d", board[i][j]);
			puts("");
		}
		exit(0);
	}
	if(board[x][y])
		dfs(depth+1);
	else
		for(i=1 ; i<=9 ; i++)
			if(!visitedrow[x][i]&&!visitedcol[y][i]&&!visitedrc[(x/3)*3+y/3][i]) {
				visitedrow[x][i]=1;
				visitedcol[y][i]=1;
				visitedrc[(x/3)*3+y/3][i]=1;
				board[x][y]=i;
				dfs(depth+1);
				visitedrow[x][i]=0;
				visitedcol[y][i]=0;
				visitedrc[(x/3)*3+y/3][i]=0;
				board[x][y]=0;
			}
}

int main(void) {
	int i, j;
	for(i=0 ; i<9 ; i++)
		for(j=0 ; j<9 ; j++) {
			scanf("%1d", &board[i][j]);
			visitedrow[i][board[i][j]]=1;
			visitedcol[j][board[i][j]]=1;
			visitedrc[(i/3)*3+j/3][board[i][j]]=1;
		}
	dfs(0);
	return 0;
}
