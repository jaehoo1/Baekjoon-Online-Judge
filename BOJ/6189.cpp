# include <iostream>
# include <queue>

typedef struct {
	int x, y;
}pos;

using namespace std;
int R, C, cou;
char map[100][101];
bool visited[100][100];
pos dest;
queue<pos> q;

void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==dest.x&&cur.y==dest.y)
				return;
			if(cur.x)
				if(map[cur.x-1][cur.y]!='*'&&!visited[cur.x-1][cur.y]) {
					q.push({cur.x-1, cur.y});
					visited[cur.x-1][cur.y]=true;
				}
			if(cur.x<R-1)
				if(map[cur.x+1][cur.y]!='*'&&!visited[cur.x+1][cur.y]) {
					q.push({cur.x+1, cur.y});
					visited[cur.x+1][cur.y]=true;
				}
			if(cur.y)
				if(map[cur.x][cur.y-1]!='*'&&!visited[cur.x][cur.y-1]) {
					q.push({cur.x, cur.y-1});
					visited[cur.x][cur.y-1]=true;
				}
			if(cur.y<C-1)
				if(map[cur.x][cur.y+1]!='*'&&!visited[cur.x][cur.y+1]) {
					q.push({cur.x, cur.y+1});
					visited[cur.x][cur.y+1]=true;
				}
		}
		cou++;
	}
}

int main(void) {
	pos start;
	scanf("%d%d", &R, &C);
	for(int i=0 ; i<R ; i++) {
		scanf("%s", map[i]);
		for(int j=0 ; j<C ; j++)
			if(map[i][j]=='B') {
				start.x=i;
				start.y=j;
			} else if(map[i][j]=='C') {
				dest.x=i;
				dest.y=j;
			}
	}
	bfs(start);
	printf("%d", cou);
	return 0;
}
