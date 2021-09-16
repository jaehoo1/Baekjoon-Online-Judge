# include <cstdio>
# include <queue>
# define	INF	1e9

using namespace std;

int N, G[126][126], D[126][126], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};

int dijkstra(void) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	fill(&D[0][0], &D[N][N], INF);
	D[0][0]=G[0][0];
	pq.push({D[0][0], {0, 0}});
	while(!pq.empty()) {
		int curx=pq.top().second.first;
		int cury=pq.top().second.second;
		int cost=pq.top().first;
		pq.pop();
		if(D[curx][cury]<cost)continue;
		for(int i=0 ; i<4 ; i++) {
			int x=curx+dx[i];
			int y=cury+dy[i];
			if(x<0||x>N-1||y<0||y>N-1)continue;
			int dist=cost+G[x][y];
			if(dist<D[x][y]) {
				D[x][y]=dist;
				pq.push({dist, {x, y}});
			}
		}
	}
	return D[N-1][N-1];
}

int main(void) {
	int T=1;
	while(scanf("%d", &N)) {
		if(!N)break;
		for(int i=0 ; i<N ; i++)
			for(int j=0 ; j<N ; j++)
				scanf("%d", &G[i][j]);
		printf("Problem %d: %d\n", T++, dijkstra());
	}
	return 0;
}
