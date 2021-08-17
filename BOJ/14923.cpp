# include <iostream>
# include <queue>

typedef struct {
	int x, y, z;
}pos;

using namespace std;
int N, M, cou;
bool map[1000][1000], visited[1000][1000][2];
pos dest;
queue<pos> q;

void bfs(pos p) {
	q.push(p);
	visited[p.x][p.y][p.z]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==dest.x&&cur.y==dest.y)
				return;
			if(cur.x) {
				if(!map[cur.x-1][cur.y]&&!visited[cur.x-1][cur.y][cur.z]) {
					q.push({cur.x-1, cur.y, cur.z});
					visited[cur.x-1][cur.y][cur.z]=true;
				} else if(!cur.z&&map[cur.x-1][cur.y]&&!visited[cur.x-1][cur.y][1]) {
					q.push({cur.x-1, cur.y, 1});
					visited[cur.x-1][cur.y][1]=true;
				}
			}
			if(cur.x<N-1) {
				if(!map[cur.x+1][cur.y]&&!visited[cur.x+1][cur.y][cur.z]) {
					q.push({cur.x+1, cur.y, cur.z});
					visited[cur.x+1][cur.y][cur.z]=true;
				} else if(!cur.z&&map[cur.x+1][cur.y]&&!visited[cur.x+1][cur.y][1]) {
					q.push({cur.x+1, cur.y, 1});
					visited[cur.x+1][cur.y][1]=true;
				}
			}
			if(cur.y) {
				if(!map[cur.x][cur.y-1]&&!visited[cur.x][cur.y-1][cur.z]) {
					q.push({cur.x, cur.y-1, cur.z});
					visited[cur.x][cur.y-1][cur.z]=true;
				} else if(!cur.z&&map[cur.x][cur.y-1]&&!visited[cur.x][cur.y-1][1]) {
					q.push({cur.x, cur.y-1, 1});
					visited[cur.x][cur.y-1][1]=true;
				}
			}
			if(cur.y<M-1) {
				if(!map[cur.x][cur.y+1]&&!visited[cur.x][cur.y+1][cur.z]) {
					q.push({cur.x, cur.y+1, cur.z});
					visited[cur.x][cur.y+1][cur.z]=true;
				} else if(!cur.z&&map[cur.x][cur.y+1]&&!visited[cur.x][cur.y+1][1]) {
					q.push({cur.x, cur.y+1, 1});
					visited[cur.x][cur.y+1][1]=true;
				}
			}
		}
		cou++;
	}
}

int main(void) {
	pos start;
	scanf("%d%d%d%d%d%d", &N, &M, &start.x, &start.y, &dest.x, &dest.y);
	start.x--;	start.y--;	start.z=0;	dest.x--;	dest.y--;
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			scanf("%d", &map[i][j]);
	bfs(start);
	if(visited[dest.x][dest.y][0]||visited[dest.x][dest.y][1])
		printf("%d", cou);
	else
		puts("-1");
	return 0;
}
