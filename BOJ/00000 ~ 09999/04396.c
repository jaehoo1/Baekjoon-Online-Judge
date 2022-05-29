# include <stdio.h>

int main(void) {
	int n, i, j, temp, k, x, y, dx[]={-1, -1, 0, 1, 1, 1, 0, -1}, dy[]={0, 1, 1, 1, 0, -1, -1, -1}, gameover=0;
	char board[10][11], print[10][11];
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
		scanf("%s", board[i]);
	for(i=0 ; i<n ; i++) {
		scanf("%s", print[i]);
		for(j=0 ; j<n ; j++)
			if(print[i][j]=='x'&&board[i][j]=='*')
				gameover=1;
	}
	for(i=0 ; i<n ; i++) {
		for(j=0 ; j<n ; j++) {
			if(gameover&&board[i][j]=='*') {
				printf("*");
				continue;
			}
			if(print[i][j]=='.') {
				printf(".");
				continue;
			}
			temp=0;
			for(k=0 ; k<8 ; k++) {
				x=i+dx[k];
				y=j+dy[k];
				if(x<0||x>=n||y<0||y>=n)
					continue;
				if(board[x][y]=='*')
					temp++;
			}
			printf("%d", temp);
		}
		puts("");
	}
	return 0;
}
