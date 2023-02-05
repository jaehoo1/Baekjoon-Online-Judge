# include <cstdio>
# include <cmath>
# include <queue>
# include <tuple>
# define	INF	1e9

using namespace std;

int h, w, dx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
char arr[100][101];

int dijkstra(int srcx, int srcy) {
	int D[100][100], dstx, dsty, max=0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	for(int i=0 ; i<h ; i++)
		for(int j=0 ; j<w ; j++) {
			D[i][j]=INF;
			if(arr[i][j]!='#'&&arr[i][j]>max) {
				max=arr[i][j];
				dstx=i;
				dsty=j;
			}
		}
	D[srcx][srcy]=0;
	pq.push(make_tuple(0, srcx, srcy));
	while(!pq.empty()) {
		int cost=get<0>(pq.top());
		int curx=get<1>(pq.top());
		int cury=get<2>(pq.top());
		pq.pop();
		if(D[curx][cury]<cost)
			continue;
		for(int i=0 ; i<8 ; i++) {
			int nx=curx+dx[i];
			int ny=cury+dy[i];
			if(nx<0||nx>=h||ny<0||ny>=w||arr[nx][ny]=='#')
				continue;
			int nextcost=cost+pow(abs(arr[nx][ny]-arr[curx][cury])+1, 2);
			if(nextcost<D[nx][ny]) {
				D[nx][ny]=nextcost;
				pq.push(make_tuple(nextcost, nx, ny));
			}
		}
	}
	return D[dstx][dsty];
}

int main(void) {
	int T, x, y;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &h, &w);
		for(int i=0 ; i<h ; i++)
			scanf("%s", arr[i]);
		scanf("%d%d", &x, &y);
		printf("%d\n", dijkstra(x, y));
	}
	return 0;
}