# include <cstdio>
# include <queue>

using namespace std;

typedef struct {
	int x, y;
}pos;

pos start, end_;
queue<pos> q;
char map[10][11];
bool visited[10][10];
int cou;

void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==end_.x&&cur.y==end_.y)
				return;
			if(cur.x)if(map[cur.x-1][cur.y]!='R'&&!visited[cur.x-1][cur.y]) {
				q.push({cur.x-1, cur.y});
				visited[cur.x-1][cur.y]=true;
			}
			if(cur.x<9)if(map[cur.x+1][cur.y]!='R'&&!visited[cur.x+1][cur.y]) {
				q.push({cur.x+1, cur.y});
				visited[cur.x+1][cur.y]=true;
			}
			if(cur.y)if(map[cur.x][cur.y-1]!='R'&&!visited[cur.x][cur.y-1]) {
				q.push({cur.x, cur.y-1});
				visited[cur.x][cur.y-1]=true;
			}
			if(cur.y<9)if(map[cur.x][cur.y+1]!='R'&&!visited[cur.x][cur.y+1]) {
				q.push({cur.x, cur.y+1});
				visited[cur.x][cur.y+1]=true;
			}
		}
		cou++;
	}
}

int main(void) {
	for(int i=0 ; i<10 ; i++) {
		scanf("%s", map[i]);
		for(int j=0 ; j<10 ; j++)
			if(map[i][j]=='B') {
				start.x=i;	start.y=j;
			} else if(map[i][j]=='L') {
				end_.x=i;	end_.y=j;
			}
	}
	bfs(start);
	printf("%d", cou-1);
	return 0;
}
