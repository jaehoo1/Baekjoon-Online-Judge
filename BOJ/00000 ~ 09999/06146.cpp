# include <cstdio>
# include <queue>

using namespace std;

int X, Y, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
bool visited[1001][1001];

int bfs(void) {
	int cou=0;
	queue<pair<int, int>> q;
	visited[500][500]=true;
	q.push({500, 500});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().first;
			int cury=q.front().second;
			q.pop();
			if(curx==X&&cury==Y)
				return cou;
			for(int i=0 ; i<4 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<0||nx>1000||ny<0||ny>1000)
					continue;
				if(visited[nx][ny])
					continue;
				visited[nx][ny]=true;
				q.push({nx, ny});
			}
		}
		cou++;
	}
}

int main(void) {
	int N, A, B;
	scanf("%d%d%d", &X, &Y, &N);
	X+=500;
	Y+=500;
	while(N--) {
		scanf("%d%d", &A, &B);
		visited[A+500][B+500]=true;
	}
	printf("%d", bfs());
	return 0;
}
