# include <cstdio>
# include <queue>

using namespace std;

int R, C, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
char map[500][501];

int bfs(int x, int y) {
	bool visited[500][500]={false, };
	int cou=0;
	queue<pair<int, int>> q;
	for(int i=0 ; i<R ; i++)
		for(int j=0 ; j<C ; j++)
			visited[i][j]=false;
	q.push({x, y});
	visited[x][y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().first;
			int cury=q.front().second;
			q.pop();
			if(map[curx][cury]=='S')
				return cou;
			for(int i=0 ; i<4 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<0||nx>=R||ny<0||ny>=C)
					continue;
				if(!visited[nx][ny]) {
					q.push({nx, ny});
					visited[nx][ny]=true;
				}
			}
		}
		cou++;
	}
	return 2;
}

int main(void) {
	scanf("%d%d", &R, &C);
	for(int i=0 ; i<R ; i++)
		scanf("%s", map[i]);
	for(int i=0 ; i<R ; i++)
		for(int j=0 ; j<C ; j++)
			if(map[i][j]=='W')
				if(bfs(i, j)<=1) {
					puts("0");
					return 0;
				}
	puts("1");
	for(int i=0 ; i<R ; i++) {
		for(int j=0 ; j<C ; j++)
			printf("%c", map[i][j]=='.'?'D':map[i][j]);
		puts("");
	}
	return 0;
}
