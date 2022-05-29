# include <cstdio>
# include <queue>

using namespace std;


int R, C, cou;
char map[1000][1001];
	
bool bfs(void) {
	int dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
	queue<pair<int, int>> q, f;
	for(int i=0 ; i<R ; i++)
		for(int j=0 ; j<C ; j++)
			if(map[i][j]=='F')
				f.push({i, j});
			else if(map[i][j]=='J')
				q.push({i, j});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().first;
			int cury=q.front().second;
			q.pop();
			if(curx<0||curx>=R||cury<0||cury>=C)
				return true;
			if(map[curx][cury]=='F')
				continue;
			for(int i=0 ; i<4 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<0||nx>=R||ny<0||ny>=C) {
					q.push({nx, ny});
					continue;
				} else if(map[nx][ny]=='F'||map[nx][ny]=='#'||map[nx][ny]=='J')
					continue;
				map[nx][ny]='J';
				q.push({nx, ny});
			}
		}
		size=f.size();
		while(size--) {
			int curx=f.front().first;
			int cury=f.front().second;
			f.pop();
			for(int i=0 ; i<4 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<0||nx>=R||ny<0||ny>=C)
					continue;
				if(map[nx][ny]=='#'||map[nx][ny]=='F')
					continue;
				map[nx][ny]='F';
				f.push({nx, ny});
			}
		}
		cou++;
	}
	return false;
}

int main(void) {
	scanf("%d%d", &R, &C);
	for(int i=0 ; i<R ; i++)
		scanf("%s", map[i]);
	if(bfs())
		printf("%d", cou);
	else
		puts("IMPOSSIBLE");
	return 0;
}
