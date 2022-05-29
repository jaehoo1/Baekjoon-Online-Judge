# include <cstdio>
# include <queue>

using namespace std;

typedef struct { int x, y; }pos;

queue<pos> q;
int N, M, map[1000][1000], cou;

void bfs(void) {
	int x, y, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().x;
			int cury=q.front().y;
			q.pop();
			for(int i=0 ; i<4 ; i++) {
				x=curx+dx[i];
				y=cury+dy[i];
				if(x<0||x>N-1||y<0||y>M-1)
					continue;
				if(!map[x][y]) {
					map[x][y]=1;
					q.push({x, y});
				}
			}
		}
		cou++;
	}
}
bool complete(void) {
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			if(!map[i][j])
				return false;
	return true;
}

int main(void) {
	scanf("%d%d", &M, &N);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j]==1)
				q.push({i, j});
		}
	bfs();
	printf("%d", complete()?cou-1:-1);
	return 0;
}
