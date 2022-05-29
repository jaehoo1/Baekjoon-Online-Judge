# include <cstdio>
# include <queue>
# include <cstring>

using namespace std;

typedef struct {
	int x, y;
}pos;

int l, cou, dx[]={-2, -1, 1, 2, 2, 1, -1, -2}, dy[]={1, 2, 2, 1, -1, -2, -2, -1};
void bfs(pos s, pos e) {
	cou=0;
	queue<pos> q;
	q=queue<pos>();
	bool visited[l+1][l+1];
	memset(visited, false, (l+1)*(l+1));
	int x, y;
	q.push({s.x, s.y});
	visited[s.x][s.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==e.x&&cur.y==e.y)
				return;
			for(int i=0 ; i<8 ; i++) {
				x=cur.x+dx[i];
				y=cur.y+dy[i];
				if(x<0||x>=l||y<0||y>=l)continue;
				if(!visited[x][y]) {
					q.push({x, y});
					visited[x][y]=true;
				}
			}
		}
		cou++;
	}
}

int main(void) {
	int T;
	pos start, end;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d%d", &l, &start.x, &start.y, &end.x, &end.y);
		bfs(start, end);
		printf("%d\n", cou);
	}
	return 0;
}
