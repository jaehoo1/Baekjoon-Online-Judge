# include <cstdio>
# include <queue>
# include <cmath>

using namespace std;

typedef struct {
	int x, y;
}pos;

int N, M, map[100][100], cou, sword;
bool visited[100][100];
queue<pos> q;

void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==N-1&&cur.y==M-1)
				return;
			if(map[cur.x][cur.y]==2)
				sword=cou+abs(cur.x-(N-1))+abs(cur.y-(M-1));
			if(cur.x)if(map[cur.x-1][cur.y]!=1&&!visited[cur.x-1][cur.y]) {
				q.push({cur.x-1, cur.y});
				visited[cur.x-1][cur.y]=true;
			}
			if(cur.x<N-1)if(map[cur.x+1][cur.y]!=1&&!visited[cur.x+1][cur.y]) {
				q.push({cur.x+1, cur.y});
				visited[cur.x+1][cur.y]=true;
			}
			if(cur.y)if(map[cur.x][cur.y-1]!=1&&!visited[cur.x][cur.y-1]) {
				q.push({cur.x, cur.y-1});
				visited[cur.x][cur.y-1]=true;
			}
			if(cur.y<M-1)if(map[cur.x][cur.y+1]!=1&&!visited[cur.x][cur.y+1]) {
				q.push({cur.x, cur.y+1});
				visited[cur.x][cur.y+1]=true;
			}
		}
		cou++;
	}
}

int main(void) {
	int min=2147483647, T;
	scanf("%d%d%d", &N, &M, &T);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			scanf("%d", &map[i][j]);
	bfs({0, 0});
	if(visited[N-1][M-1])
		min=cou;
	if(sword&&sword<min)
		min=sword;
	if(min>T)
		puts("Fail");
	else
		printf("%d", min);
	return 0;
}
