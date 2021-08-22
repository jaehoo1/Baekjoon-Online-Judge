# include <cstdio>
# include <queue>

using namespace std;

typedef struct {
	int x, y;
}pos;

int n, m, cou, map[1000][1000], dist[1000][1000];
bool visited[1000][1000];

void bfs(pos p) {
	int dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1}, x, y;
	queue<pos> q;
	q.push(p);
	visited[p.x][p.y]=true;
	dist[p.x][p.y]=cou;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			for(int i=0 ; i<4 ; i++) {
				x=cur.x+dx[i];
				y=cur.y+dy[i];
				if(x<0||x>=n||y<0||y>=m)
					continue;
				if(map[x][y]&&!visited[x][y]) {
					q.push({x, y});
					visited[x][y]=true;
					dist[x][y]=cou+1;
				}
			}
		}
		cou++;
	}
}

int main(void) {
	pos start;
	scanf("%d%d", &n, &m);
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j]==2)
				start={i, j};
		}
	bfs(start);
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			if(map[i][j]&&!visited[i][j])
				dist[i][j]=-1;
			printf("%d ", dist[i][j]);
		}
		puts("");
	}
	return 0;
}
