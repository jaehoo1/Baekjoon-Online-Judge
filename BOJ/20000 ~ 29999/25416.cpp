# include <cstdio>
# include <queue>

using namespace std;

int arr[5][5], dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};

int bfs(int sx, int sy) {
	bool visited[5][5]={false, };
	queue<pair<int, int>> q;
	int cou=0;
	visited[sx][sy]=true;
	q.push({sx, sy});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().first;
			int cury=q.front().second;
			q.pop();
			if(arr[curx][cury]==1)
				return cou;
			for(int i=0 ; i<4 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<0||nx>=5||ny<0||ny>=5||arr[nx][ny]==-1||visited[nx][ny])
					continue;
				visited[nx][ny]=true;
				q.push({nx, ny});
			}
		}
		cou++;
	}
	return -1;
}

int main(void) {
	int r, c;
	for(int i=0 ; i<5 ; i++)
		for(int j=0 ; j<5 ; j++)
			scanf("%d", &arr[i][j]);
	scanf("%d%d", &r, &c);
	printf("%d", bfs(r, c));
	return 0;
}