# include <stdio.h>

char str[1000][1001], c;
int R, C, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1}, visited[1000][1001];

void fill(int x, int y) {
	int i;
	if(c==str[x][y])
		return;
	visited[x][y]=1;
	for(i=0 ; i<4 ; i++) {
		if(x+dx[i]<0||x+dx[i]>=R||y+dy[i]<0||y+dy[i]>=C)
			continue;
		if(visited[x+dx[i]][y+dy[i]])
			continue;
		if(str[x][y]==str[x+dx[i]][y+dy[i]])
			fill(x+dx[i], y+dy[i]);
	}
	str[x][y]=c;
}

int main(void) {
	int i, X, Y, K;
	scanf("%d%d", &R, &C);
	for(i=0 ; i<R ; i++)
		scanf("%s", str[i]);
	scanf("%d%d%d", &X, &Y, &K);
	c=K+'0';
	fill(X, Y);
	for(i=0 ; i<R ; i++)
		printf("%s\n", str[i]);
	return 0;
}
