# include <cstdio>
# include <queue>
# include <cstring>

using namespace std;

typedef struct {
	int x, y;
}pos;

int N, M, cou, max_;
char map[50][51];
bool visited[50][50];
queue<pos> q;

void bfs(pos start) {
	cou=0;
	q=queue<pos>();
	memset(visited, false, 2500);
	q.push({start.x, start.y});
	visited[start.x][start.y]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			pos cur=q.front();
			q.pop();
			if(cur.x)if(map[cur.x-1][cur.y]=='L'&&!visited[cur.x-1][cur.y]) {
				q.push({cur.x-1, cur.y});
				visited[cur.x-1][cur.y]=true;
			}
			if(cur.x<N-1)if(map[cur.x+1][cur.y]=='L'&&!visited[cur.x+1][cur.y]) {
				q.push({cur.x+1, cur.y});
				visited[cur.x+1][cur.y]=true;
			}
			if(cur.y)if(map[cur.x][cur.y-1]=='L'&&!visited[cur.x][cur.y-1]) {
				q.push({cur.x, cur.y-1});
				visited[cur.x][cur.y-1]=true;
			}
			if(cur.y<M-1)if(map[cur.x][cur.y+1]=='L'&&!visited[cur.x][cur.y+1]) {
				q.push({cur.x, cur.y+1});
				visited[cur.x][cur.y+1]=true;
			}
		}
		cou++;
	}
}

int main(void) {
	int ptr=0;
	pos land[2500];
	scanf("%d%d", &N, &M);
	for(int i=0 ; i<N ; i++) {
		scanf("%s", map[i]);
		for(int j=0 ; j<M ; j++)
			if(map[i][j]=='L')
				land[ptr++]={i, j};
	}
	for(int i=0 ; i<ptr ; i++) {
		cou=0;
		memset(visited, false, 2500);
		bfs(land[i]);
		if(cou>max_)
			max_=cou;
	}
	printf("%d", max_-1);
	return 0;
}
