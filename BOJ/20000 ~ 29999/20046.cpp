# include <cstdio>
# include <queue>
# define	INF	1e9

using namespace std;

int m, n, map[1000][1000];

int dijkstra(int sx, int sy) {
	int D[1000][1000], x, y, dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
	for(int i=0 ; i<m ; i++)
		for(int j=0 ; j<n ; j++)
			D[i][j]=INF;
    if(map[sx][sy]==-1)return -1;
	D[sx][sy]=map[sx][sy];
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({D[sx][sy], {sx, sy}});
	while(!pq.empty()) {
		int dist=pq.top().first;
		int curx=pq.top().second.first;
		int cury=pq.top().second.second;
		pq.pop();
		if(D[curx][cury]<dist)continue;
		for(int i=0 ; i<4 ; i++) {
			x=curx+dx[i];
			y=cury+dy[i];
			if(x<0||x>m-1||y<0||y>n-1)
				continue;
			if(map[x][y]==-1)
				continue;
			int cost=dist+map[x][y];
			if(cost<D[x][y]) {
				D[x][y]=cost;
				pq.push({cost, {x, y}});
			}
		}
	}
	return D[m-1][n-1]!=INF?D[m-1][n-1]:-1;
}

int main(void) {
	scanf("%d%d", &m, &n);
	for(int i=0 ; i<m ; i++)
		for(int j=0 ; j<n ; j++)
			scanf("%d", &map[i][j]);
	printf("%d", dijkstra(0, 0));
	return 0;
}
