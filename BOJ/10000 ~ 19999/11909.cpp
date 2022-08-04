# include <cstdio>
# include <queue>
# include <tuple>
# define	INF	1e9

using namespace std;

int n, arr[2222][2222];

int dijkstra(void) {
	int D[2222][2222], dx[]={0, 1}, dy[]={1, 0};
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			D[i][j]=INF;
	D[0][0]=0;
	pq.push(make_tuple(0, 0, 0));
	while(!pq.empty()) {
		int curcost=get<0>(pq.top());
		int curx=get<1>(pq.top());
		int cury=get<2>(pq.top());
		pq.pop();
		for(int i=0 ; i<2 ; i++) {
			int nx=curx+dx[i];
			int ny=cury+dy[i];
			if(nx>=n||ny>=n)
				continue;
			int nextcost=curcost;
			if(arr[curx][cury]<=arr[nx][ny])
				nextcost+=arr[nx][ny]-arr[curx][cury]+1;
			if(nextcost<D[nx][ny]) {
				D[nx][ny]=nextcost;
				pq.push(make_tuple(nextcost, nx, ny));
			}
		}
	}
	return D[n-1][n-1];
}

int main(void) {
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			scanf("%d", &arr[i][j]);
	printf("%d", dijkstra());
	return 0;
}