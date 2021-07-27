# include <iostream>
# include <queue>

typedef struct {
	int x, y;
}pos;

using namespace std;
int N, M, cou;
bool map[100][100], visited[100][100];
queue<pos> q;

void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x+1==N&&cur.y+1==M)
				return;
			if(cur.x>0)
				if(map[cur.x-1][cur.y]&&!visited[cur.x-1][cur.y]) {
					q.push({cur.x-1, cur.y});
					visited[cur.x-1][cur.y]=true;
				}
			if(cur.x<N-1)
				if(map[cur.x+1][cur.y]&&!visited[cur.x+1][cur.y]) {
					q.push({cur.x+1, cur.y});
					visited[cur.x+1][cur.y]=true;
				}
			if(cur.y>0)
				if(map[cur.x][cur.y-1]&&!visited[cur.x][cur.y-1]) {
					q.push({cur.x, cur.y-1});
					visited[cur.x][cur.y-1]=true;
				}
			if(cur.y<M-1)
				if(map[cur.x][cur.y+1]&&!visited[cur.x][cur.y+1]) {
					q.push({cur.x, cur.y+1});
					visited[cur.x][cur.y+1]=true;
				}
		}
		cou++;
	}
}

int main(void) {
	scanf("%d%d", &N, &M);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			scanf("%1d", &map[i][j]);
	bfs({0, 0});
	printf("%d", cou+1);
	return 0;
}
