# include <stdio.h>

char arr[1000][1001];
int N, dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};

void dfs(int x, int y) {
	int nx, ny, i;
	arr[x][y]='.';
	for(i=0 ; i<4 ; i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||nx>=N||ny<0||ny>=N)
			continue;
		if(arr[nx][ny]=='*')
			dfs(nx, ny);
	}
}

int main(void) {
	int i, j, cou=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%s", arr[i]);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
			if(arr[i][j]=='*') {
				dfs(i, j);
				cou++;
			}
	printf("%d", cou);
	return 0;
}