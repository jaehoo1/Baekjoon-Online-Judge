# include <cstdio>
# include <queue>
# include <cstring>

using namespace std;

typedef struct {
	int x, y;
}pos;

pos arr[10];
queue<pos> q;
char map[1000][1001];
bool visited[1000][1000];
int H, W, N, cou, res;

void bfs(pos s, pos e) {
	cou=0;
	memset(visited, false, 1000000);
	q=queue<pos>();
	q.push(s);
	visited[s.x][s.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x==e.x&&cur.y==e.y)
				return;
			if(cur.x)if(map[cur.x-1][cur.y]!='X'&&!visited[cur.x-1][cur.y]) {
				q.push({cur.x-1, cur.y});
				visited[cur.x-1][cur.y]=true;
			}
			if(cur.x<H-1)if(map[cur.x+1][cur.y]!='X'&&!visited[cur.x+1][cur.y]) {
				q.push({cur.x+1, cur.y});
				visited[cur.x+1][cur.y]=true;
			}
			if(cur.y)if(map[cur.x][cur.y-1]!='X'&&!visited[cur.x][cur.y-1]) {
				q.push({cur.x, cur.y-1});
				visited[cur.x][cur.y-1]=true;
			}
			if(cur.y<W-1)if(map[cur.x][cur.y+1]!='X'&&!visited[cur.x][cur.y+1]) {
				q.push({cur.x, cur.y+1});
				visited[cur.x][cur.y+1]=true;
			}
		}
		cou++;
	}
}

int main(void) {
	scanf("%d%d%d", &H, &W, &N);
	for(int i=0 ; i<H ; i++) {
		scanf("%s", map[i]);
		for(int j=0 ; j<W ; j++)
			if(map[i][j]=='S')
				arr[0]={i, j};
			else if(map[i][j]>='1'&&map[i][j]<='9')
				arr[map[i][j]-'0']={i, j};
	}
	for(int i=0 ; i<N ; i++) {
		bfs(arr[i], arr[i+1]);
		res+=cou;
	}
	printf("%d", res);
	return 0;
}
