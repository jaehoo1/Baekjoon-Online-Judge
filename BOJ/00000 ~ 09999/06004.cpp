# include <cstdio>
# include <queue>

using namespace std;

int X, Y;
char str[150][151];

int bfs(void) {
	int cou=0, dx[8]={-2, -1, 1, 2, 2, 1, -1, -2}, dy[8]={1, 2, 2, 1, -1, -2, -2, -1};
	pair<int, int> src;
	bool visited[150][150]={false, };
	queue<pair<int, int>> q;
	for(int i=0 ; i<X ; i++)
		for(int j=0 ; j<Y ; j++)
			if(str[i][j]=='K') {
				src.first=i;
				src.second=j;
			}
	visited[src.first][src.second]=true;
	q.push(src);
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().first;
			int cury=q.front().second;
			q.pop();
			if(str[curx][cury]=='H')
				return cou;
			for(int i=0 ; i<8 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<0||nx>=X||ny<0||ny>=Y||visited[nx][ny]||str[nx][ny]=='*')
					continue;
				visited[nx][ny]=true;
				q.push({nx, ny});
			}
		}
		cou++;
	}
}

int main(void) {
	scanf("%d%d", &Y, &X);
	for(int i=0 ; i<X ; i++)
		scanf("%s", str[i]);
	printf("%d", bfs());
	return 0;
}