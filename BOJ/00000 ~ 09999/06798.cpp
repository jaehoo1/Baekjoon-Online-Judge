# include <cstdio>
# include <cmath>
# include <queue>

using namespace std;

pair<int, int> A, B;
int dx[8]={-2, -1, 1, 2, 2, 1, -1, -2}, dy[8]={1, 2, 2, 1, -1, -2, -2, -1};

pair<int, int> position(pair<int, int> p) {
	pair<int, int> temp;
	temp.first=abs(p.second-8);
	temp.second=p.first-1;
	return temp;
}

int bfs(void) {
	bool visited[8][8]={false, };
	queue<pair<int, int>> q;
	int cou=0;
	visited[A.first][A.second]=true;
	q.push({A.first, A.second});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().first;
			int cury=q.front().second;
			q.pop();
			if(curx==B.first&&cury==B.second)
				return cou;
			for(int i=0 ; i<8 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<0||nx>=8||ny<0||ny>=8)
					continue;
				if(visited[nx][ny])
					continue;
				visited[nx][ny]=true;
				q.push({nx, ny});
			}
		}
		cou++;
	}
}

int main(void) {
	scanf("%d%d%d%d", &A.first, &A.second, &B.first, &B.second);
	A=position(A);
	B=position(B);
	printf("%d", bfs());
	return 0;
}