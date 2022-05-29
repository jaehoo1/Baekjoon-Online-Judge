# include <cstdio>
# include <queue>

using namespace std;

typedef struct {
	int x, y, z;
}pos;

int N, M, K, cou;
bool visited[1000][1000][11], map[1000][1000];
queue<pos> q;

void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y][p.z]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==N-1&&cur.y==M-1)
				return;
			if(cur.x)
				if(!map[cur.x-1][cur.y]&&!visited[cur.x-1][cur.y][cur.z]) {
					q.push({cur.x-1, cur.y, cur.z});
					visited[cur.x-1][cur.y][cur.z]=true;
				} else if(cur.z<K&&map[cur.x-1][cur.y]&&!visited[cur.x-1][cur.y][cur.z+1]) {
					q.push({cur.x-1, cur.y, cur.z+1});
					visited[cur.x-1][cur.y][cur.z+1]=true;
				}
			if(cur.x<N-1)
				if(!map[cur.x+1][cur.y]&&!visited[cur.x+1][cur.y][cur.z]) {
					q.push({cur.x+1, cur.y, cur.z});
					visited[cur.x+1][cur.y][cur.z]=true;
				} else if(cur.z<K&&map[cur.x+1][cur.y]&&!visited[cur.x+1][cur.y][cur.z+1]) {
					q.push({cur.x+1, cur.y, cur.z+1});
					visited[cur.x+1][cur.y][cur.z+1]=true;
				}
			if(cur.y)
				if(!map[cur.x][cur.y-1]&&!visited[cur.x][cur.y-1][cur.z]) {
					q.push({cur.x, cur.y-1, cur.z});
					visited[cur.x][cur.y-1][cur.z]=true;
				} else if(cur.z<K&&map[cur.x][cur.y-1]&&!visited[cur.x][cur.y-1][cur.z+1]) {
					q.push({cur.x, cur.y-1, cur.z+1});
					visited[cur.x][cur.y-1][cur.z+1]=true;
				}
			if(cur.y<M-1)
				if(!map[cur.x][cur.y+1]&&!visited[cur.x][cur.y+1][cur.z]) {
					q.push({cur.x, cur.y+1, cur.z});
					visited[cur.x][cur.y+1][cur.z]=true;
				} else if(cur.z<K&&map[cur.x][cur.y+1]&&!visited[cur.x][cur.y+1][cur.z+1]) {
					q.push({cur.x, cur.y+1, cur.z+1});
					visited[cur.x][cur.y+1][cur.z+1]=true;
				}
		}
		cou++;
	}
}
bool arrived(void) {
	for(int i=0 ; i<=K ; i++)
		if(visited[N-1][M-1][i])
			return true;
	return false;
}

int main(void) {
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			scanf("%1d", &map[i][j]);
	bfs({0, 0, 0});
	if(arrived())
		printf("%d", cou+1);
	else
		puts("-1");
	return 0;
}
