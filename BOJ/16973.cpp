# include <iostream>
# include <queue>

using namespace std;

typedef struct {
	int x, y;
}pos;

int N, M, H, W, FR, FC, cou;
bool map[1002][1002], visited[1002][1002];
queue<pos> q;

bool cango(pos cur, char vec) {
	if(vec=='U') {
		if(cur.x==1)return false;
		if(visited[cur.x-1][cur.y])return false;
		for(int j=cur.y ; j<cur.y+W ; j++)
			if(map[cur.x-1][j])
				return false;
		return true;
	} else if(vec=='D') {
		if(cur.x+H-1==N)return false;
		if(visited[cur.x+1][cur.y])return false;
		for(int j=cur.y ; j<cur.y+W ; j++)
			if(map[cur.x+H][j])
				return false;
		return true;
	} else if(vec=='L') {
		if(cur.y==1)return false;
		if(visited[cur.x][cur.y-1])return false;
		for(int i=cur.x ; i<cur.x+H ; i++)
			if(map[i][cur.y-1])
				return false;
		return true;
	} else if(vec=='R') {
		if(cur.y+W-1==M)return false;
		if(visited[cur.x][cur.y+1])return false;
		for(int i=cur.x ; i<cur.x+H ; i++)
			if(map[i][cur.y+W])
				return false;
		return true;
	}
}
void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==FR&&cur.y==FC)
				return;
			if(cango(cur, 'U')) {
				q.push({cur.x-1, cur.y});
				visited[cur.x-1][cur.y]=true;
			}
			if(cango(cur, 'D')) {
				q.push({cur.x+1, cur.y});
				visited[cur.x+1][cur.y]=true;
			}
			if(cango(cur, 'L')) {
				q.push({cur.x, cur.y-1});
				visited[cur.x][cur.y-1]=true;
			}
			if(cango(cur, 'R')) {
				q.push({cur.x, cur.y+1});
				visited[cur.x][cur.y+1]=true;
			}
		}
		cou++;
	}
}

int main(void) {
	int SR, SC;
	scanf("%d%d", &N, &M);
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=M ; j++)
			scanf("%1d", &map[i][j]);
	scanf("%d%d%d%d%d%d", &H, &W, &SR, &SC, &FR, &FC);
	bfs({SR, SC});
	if(visited[FR][FC])
		printf("%d", cou);
	else
		puts("-1");
	return 0;
}
