# include <iostream>
# include <queue>

typedef struct {
	int x, y;
}pos;

using namespace std;
int N, map[65][65];
bool visited[65][65];
queue<pos> q;

bool cango(pos cur, char vec) {
	int jump=map[cur.x][cur.y];
	if(vec=='R') {
		if(cur.y+jump>N)return false;
		if(visited[cur.x][cur.y+jump])return false;
		return true;
	} else if(vec=='D') {
		if(cur.x+jump>N)return false;
		if(visited[cur.x+jump][cur.y])return false;
		return true;
	}
}
void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		pos cur=q.front();
		q.pop();
		if(cur.x==N&&cur.y==N)
			return;
		if(cango(cur, 'R')) {
			q.push({cur.x, cur.y+map[cur.x][cur.y]});
			visited[cur.x][cur.y+map[cur.x][cur.y]]=true;
		}
		if(cango(cur, 'D')) {
			q.push({cur.x+map[cur.x][cur.y], cur.y});
			visited[cur.x+map[cur.x][cur.y]][cur.y]=true;
		}
	}
}

int main(void) {
	scanf("%d", &N);
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=N ; j++)
			scanf("%d", &map[i][j]);
	bfs({1, 1});
	if(visited[N][N])
		puts("HaruHaru");
	else
		puts("Hing");
	return 0;
}
