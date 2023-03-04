# include <cstdio>
# include <queue>

using namespace std;

void bfs(int H, int W, int dstx, int dsty) {
	int cou=0, dx[8]={-2, -1, 1, 2, 2, 1, -1, -2}, dy[8]={1, 2, 2, 1, -1, -2, -2, -1};
	queue<pair<int, int>> q;
	bool visited[101][101]={false, };
	visited[H][1]=true;
	q.push({H, 1});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().first;
			int cury=q.front().second;
			q.pop();
			if(curx==dstx&&cury==dsty) {
				printf("%d", cou);
				return;
			}
			for(int i=0 ; i<8 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<1||nx>H||ny<1||ny>W||visited[nx][ny])
					continue;
				visited[nx][ny]=true;
				q.push({nx, ny});
			}
		}
		cou++;
	}
	puts("NEVAR");
}

int main(void) {
	int n, m, i, j;
	scanf("%d%d%d%d", &n, &m, &i, &j);
	bfs(m, n, m-j+1, i);
	return 0;
}