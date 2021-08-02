# include <stdio.h>

int N, M, bef[30][30], aft[30][30];

void dfs(int x, int y, int num) {
	int cur=bef[x][y];
	bef[x][y]=num;
	if(x>0)if(cur==bef[x-1][y])dfs(x-1, y, num);
	if(x<N-1)if(cur==bef[x+1][y])dfs(x+1, y, num);
	if(y>0)if(cur==bef[x][y-1])dfs(x, y-1, num);
	if(y<M-1)if(cur==bef[x][y+1])dfs(x, y+1, num);
}
int issame(void) {
	int i, j;
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			if(bef[i][j]!=aft[i][j])
				return 0;
	return 1;
}

int main(void) {
	int i, j;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			scanf("%d", &bef[i][j]);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			scanf("%d", &aft[i][j]);
	if(issame()) {
		puts("YES");
		return 0;
	}
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			if(bef[i][j]!=aft[i][j]) {
				dfs(i, j, aft[i][j]);
				if(issame())puts("YES");
				else	puts("NO");
				return 0;
			}
	return 0;
}
