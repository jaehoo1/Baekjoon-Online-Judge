# include <cstdio>
# include <queue>
# include <tuple>

using namespace std;

int L, R, C, dx[]={0, 0, -1, 1, 0, 0}, dy[]={-1, 1, 0, 0, 0, 0}, dz[]={0, 0, 0, 0, -1, 1};
char map[30][30][31];
tuple<int, int, int> start;

int bfs(void) {
	int cou=0;
	bool visited[30][30][30]={false, };
	queue<tuple<int, int, int>> q;
	q.push(start);
	visited[get<0>(start)][get<1>(start)][get<2>(start)]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			tuple<int, int, int> t=q.front();
			int curx=get<0>(t);
			int cury=get<1>(t);
			int curz=get<2>(t);
			q.pop();
			if(map[curx][cury][curz]=='E')
				return cou;
			for(int i=0 ; i<6 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				int nz=curz+dz[i];
				if(nx<0||nx>=L||ny<0||ny>=R||nz<0||nz>=C)
					continue;
				if(visited[nx][ny][nz]||map[nx][ny][nz]=='#')
					continue;
				q.push(make_tuple(nx, ny, nz));
				visited[nx][ny][nz]=true;
			}
		}
		cou++;
	}
	return -1;
}

int main(void) {
	int x;
	while(scanf("%d%d%d", &L, &R, &C)) {
		if(!L&&!R&&!C)
			break;
		for(int i=0 ; i<L ; i++)
			for(int j=0 ; j<R ; j++) {
				scanf("%s", map[i][j]);
				for(int k=0 ; k<C ; k++)
					if(map[i][j][k]=='S')
						start=make_tuple(i, j, k);
			}
		x=bfs();
		if(x==-1)
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n", x);
	}
	return 0;
}