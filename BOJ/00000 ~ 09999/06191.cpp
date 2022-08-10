# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

int R, C, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
char str[113][78];

vector<pair<int, int>> bfs(void) {
	pair<int, int> parent[113][77];
	bool visited[113][77]={false, };
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	visited[0][0]=true;
	parent[0][0]={0, 0};
	q.push({0, 0});
	while(!q.empty()) {
		int curx=q.front().first;
		int cury=q.front().second;
		q.pop();
		if(curx==R-1&&cury==C-1)
			break;
		for(int i=0 ; i<4 ; i++) {
			int nx=curx+dx[i];
			int ny=cury+dy[i];
			if(nx<0||nx>=R||ny<0||ny>=C)
				continue;
			if(visited[nx][ny]||str[nx][ny]=='*')
				continue;
			visited[nx][ny]=true;
			parent[nx][ny]={curx, cury};
			q.push({nx, ny});
		}
	}
	pair<int, int> p={R-1, C-1};
	while(p.first!=0||p.second!=0) {
		v.push_back({p.first+1, p.second+1});
		p=parent[p.first][p.second];
	}
	v.push_back({1, 1});
	reverse(v.begin(), v.end());
	return v;
}

int main(void) {
	scanf("%d%d", &R, &C);
	for(int i=0 ; i<R ; i++)
		scanf("%s", str[i]);
	vector<pair<int, int>> v=bfs();
	for(int i=0 ; i<v.size() ; i++)
		printf("%d %d\n", v[i].first, v[i].second);
	return 0;
}