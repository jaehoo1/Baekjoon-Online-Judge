# include <iostream>
# include <queue>

typedef struct {
	int x, y;
}pos;

using namespace std;
int n, m, cou;
char map[3000][3001];
bool visited[3000][3000], reach;
queue<pos> q;

void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(map[cur.x][cur.y]>'2') {
				reach=true;
				return;
			}
			if(cur.x)
				if(map[cur.x-1][cur.y]!='1'&&!visited[cur.x-1][cur.y]) {
					q.push({cur.x-1, cur.y});
					visited[cur.x-1][cur.y]=true;
				}
			if(cur.x<n-1)
				if(map[cur.x+1][cur.y]!='1'&&!visited[cur.x+1][cur.y]) {
					q.push({cur.x+1, cur.y});
					visited[cur.x+1][cur.y]=true;
				}
			if(cur.y)
				if(map[cur.x][cur.y-1]!='1'&&!visited[cur.x][cur.y-1]) {
					q.push({cur.x, cur.y-1});
					visited[cur.x][cur.y-1]=true;
				}
			if(cur.y<m-1)
				if(map[cur.x][cur.y+1]!='1'&&!visited[cur.x][cur.y+1]) {
					q.push({cur.x, cur.y+1});
					visited[cur.x][cur.y+1]=true;
				}
		}
		cou++;
	}
}

int main(void) {
	bool found=false;
	pos start;
	scanf("%d%d", &n, &m);
	for(int i=0 ; i<n ; i++) {
		scanf("%s", map[i]);
		if(!found)
			for(int j=0 ; j<m ; j++)
				if(map[i][j]=='2') {
					start.x=i;
					start.y=j;
					found=true;
				}
	}
	bfs(start);
	if(reach)
		printf("TAK\n%d", cou);
	else
		puts("NIE");
	return 0;
}
