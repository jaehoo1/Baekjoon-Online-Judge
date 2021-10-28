# include <stdio.h>

typedef enum { false, true }bool;

int R, C, max, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
char str[20][21];
bool visited[26];

void dfs(int x, int y, int depth) {
	int i, nx, ny;
	if(depth>max)
		max=depth;
	visited[str[x][y]-'A']=true;
	for(i=0 ; i<4 ; i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||nx>R-1||ny<0||ny>C-1)
			continue;
		if(!visited[str[nx][ny]-'A'])
			dfs(nx, ny, depth+1);		
	}
	visited[str[x][y]-'A']=false;
}

int main(void) {
	int i;
	scanf("%d%d", &R, &C);
	for(i=0 ; i<R ; i++)
		scanf("%s", str[i]);
	dfs(0, 0, 1);
	printf("%d", max);
	return 0;
}
