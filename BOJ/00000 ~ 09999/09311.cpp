# include <cstdio>
# include <queue>

using namespace std;

char G[15][16];
int R, C, sx, sy, dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};

void bfs(void) {
	int cou=0;
	queue<pair<int, int>> q;
	bool visited[15][15]={false, };
	visited[sx][sy]=true;
	q.push({sx, sy});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().first;
			int cury=q.front().second;
			q.pop();
			if(G[curx][cury]=='G') {
				printf("Shortest Path: %d\n", cou);
				return;
			}
			for(int i=0 ; i<4 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<0||nx>=R||ny<0||ny>=C||visited[nx][ny]||G[nx][ny]=='X')
					continue;
				visited[nx][ny]=true;
				q.push({nx, ny});
			}
		}
		cou++;
	}
	puts("No Exit");
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &R, &C);
		for(int i=0 ; i<R ; i++) {
			scanf("%s", G[i]);
			for(int j=0 ; j<C ; j++)
				if(G[i][j]=='S') {
					sx=i;
					sy=j;
				}
		}
		bfs();
	}
	return 0;
}