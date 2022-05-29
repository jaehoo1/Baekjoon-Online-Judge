# include <cstdio>
# include <queue>

using namespace std;

typedef struct {
	int x, y;
}pos;

int n, m, map[500][500], cou;
bool visited[500][500];
queue<pos> q;

bool cango(pos cur, char vec) {
	int dist=map[cur.x][cur.y];
	if(vec=='U') {
		if(cur.x-dist<0)return false;
		if(visited[cur.x-dist][cur.y])return false;
	}
	if(vec=='D') {
		if(cur.x+dist>=n)return false;
		if(visited[cur.x+dist][cur.y])return false;
	}
	if(vec=='L') {
		if(cur.y-dist<0)return false;
		if(visited[cur.x][cur.y-dist])return false;
	}
	if(vec=='R') {
		if(cur.y+dist>=m)return false;
		if(visited[cur.x][cur.y+dist])return false;
	}
	return true;
}
void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==n-1&&cur.y==m-1)return;
			int dist=map[cur.x][cur.y];
			if(cango(cur, 'U')) {
				q.push({cur.x-dist, cur.y});
				visited[cur.x-dist][cur.y]=true;
			}
			if(cango(cur, 'D')) {
				q.push({cur.x+dist, cur.y});
				visited[cur.x+dist][cur.y]=true;
			}
			if(cango(cur, 'L')) {
				q.push({cur.x, cur.y-dist});
				visited[cur.x][cur.y-dist]=true;
			}
			if(cango(cur, 'R')) {
				q.push({cur.x, cur.y+dist});
				visited[cur.x][cur.y+dist]=true;
			}
		}
		cou++;
	}
}

int main(void) {
	scanf("%d%d", &n, &m);
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			scanf("%1d", &map[i][j]);
	bfs({0, 0});
	if(visited[n-1][m-1])
		printf("%d", cou);
	else
		puts("IMPOSSIBLE");
	return 0;
}
