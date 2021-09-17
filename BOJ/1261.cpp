# include <cstdio>
# include <queue>
# define	INF	1e9

using namespace std;

int M, N;
bool map[111][111];

int dijkstra(void) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	int D[101][101], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			D[i][j]=INF;
	D[0][0]=map[0][0];
	pq.push({D[0][0], {0, 0}});
	while(!pq.empty()) {
		int cost=pq.top().first;
		int curx=pq.top().second.first;
		int cury=pq.top().second.second;
		pq.pop();
		if(D[curx][cury]<cost)continue;
		for(int i=0 ; i<4 ; i++) {
			int x=curx+dx[i];
			int y=cury+dy[i];
			if(x<0||x>N-1||y<0||y>M-1)continue;
			int dist=cost+map[x][y];
			if(dist<D[x][y]) {
				pq.push({dist, {x, y}});
				D[x][y]=dist;
			}
		}
	}
	return D[N-1][M-1];
}

int main(void) {
	scanf("%d%d", &M, &N);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<M ; j++)
			scanf("%1d", &map[i][j]);
	printf("%d", dijkstra());
	return 0;
}
