# include <cstdio>
# include <queue>

using namespace std;

int N, M, map[8][8], res, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1}, WALL, SIZE;

void bfs(void) {
	bool visited[8][8]={false, };
	queue<pair<int, int>> q;
	int virus=0;
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			if(map[i][j]==2) {
				q.push({i, j});
				visited[i][j]=true;
				virus++;
			}
	while(!q.empty()) {
		int curx=q.front().first;
		int cury=q.front().second;
		q.pop();
		for(int i=0 ; i<4 ; i++) {
			int nx=curx+dx[i];
			int ny=cury+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M)
				continue;
			if(map[nx][ny]||visited[nx][ny])
				continue;
			q.push({nx, ny});
			visited[nx][ny]=true;
			virus++;
		}
	}
	if(SIZE-WALL-virus>res)
		res=SIZE-WALL-virus;
}
void dfs(int depth) {
	if(depth==3) {
		bfs();
		return;
	}
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++) {
			if(map[i][j])
				continue;
			map[i][j]=true;
			dfs(depth+1);
			map[i][j]=false;
		}
}

int main(void) {
	scanf("%d%d", &N, &M);
	SIZE=N*M;
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j]==1)
				WALL++;
		}
	WALL+=3;
	dfs(0);
	printf("%d", res);
	return 0;
}
