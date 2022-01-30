# include <cstdio>
# include <cmath>
# include <queue>
# define	INF	1e9

using namespace std;

int N, map[1000][1000];

int dijkstra(void) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	int D[1000][1000], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			D[i][j]=INF;
	pq.push({0, {0, 0}});
	D[0][0]=0;
	while(!pq.empty()) {
		int curcost=pq.top().first;
		int curx=pq.top().second.first;
		int cury=pq.top().second.second;
		pq.pop();
		if(curcost<D[curx][cury])
			continue;
		for(int i=0 ; i<4 ; i++) {
			int nx=curx+dx[i];
			int ny=cury+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=N)
				continue;
			int ncost=max(curcost, abs(map[curx][cury]-map[nx][ny]));
			if(ncost<D[nx][ny]) {
				pq.push({ncost, {nx, ny}});
				D[nx][ny]=ncost;
			}
		}
	}
	return D[N-1][N-1];
}

int main(void) {
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			scanf("%d", &map[i][j]);
	printf("%d", dijkstra());
	return 0;
}
