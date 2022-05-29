# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

typedef struct { int x, y, size, exp; }shark;

shark s;
int N, map[20][20], time, dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

pair<int, pair<int, int>> bfs(void) {
	int cou=0;
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	bool visited[20][20]={false, };
	visited[s.x][s.y]=true;
	q.push({s.x, s.y});
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int curx=q.front().first;
			int cury=q.front().second;
			q.pop();
			if(map[curx][cury]&&map[curx][cury]<s.size)
				v.push_back({curx, cury});
			for(int i=0 ; i<4 ; i++) {
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				if(nx<0||nx>=N||ny<0||ny>=N)
					continue;
				if(map[nx][ny]>s.size||visited[nx][ny])
					continue;
				visited[nx][ny]=true;
				q.push({nx, ny});
			}
		}
		if(v.size()) {
			sort(v.begin(), v.end());
			return {cou, {v[0].first, v[0].second}};
		}
		cou++;
	}
	return {-1, {-1, -1}};
}
void eat(int dist, int fishx, int fishy) {
	time+=dist;
	map[fishx][fishy]=0;
	s.x=fishx;
	s.y=fishy;
	s.exp++;
	if(s.exp==s.size) {
		s.exp=0;
		s.size++;
	}
}

int main(void) {
	s.exp=0;
	s.size=2;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j]==9) {
				s.x=i;
				s.y=j;
				map[i][j]=0;
			}
		}
	while(true) {
		pair<int, pair<int, int>> temp=bfs();
		if(temp.first==-1)
			break;
		eat(temp.first, temp.second.first, temp.second.second);
	}
	printf("%d", time);
	return 0;
}
