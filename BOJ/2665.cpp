# include <cstdio>
# include <queue>
# define	INF	1e9

using namespace std;

int n;
bool map[55][55];

int dijkstra(void) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	int D[51][51], dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			D[i][j]=INF;
	if(map[0][0])D[0][0]=0;
	else	D[0][0]=1;
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
			if(x<0||x>n-1||y<0||y>n-1)continue;
			int dist=cost;
			if(!map[x][y])dist++;
			if(dist<D[x][y]) {
				pq.push({dist, {x, y}});
				D[x][y]=dist;
			}
		}
	}
	return D[n-1][n-1];
}

int main(void) {
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			scanf("%1d", &map[i][j]);
	printf("%d", dijkstra());
	return 0;
}
