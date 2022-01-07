# include <cstdio>
# include <queue>
# define	LL	long long
# define	INF	1e18
using namespace std;

int N, T, arr[100][100];

int abs(int x) { return x<0?-x:x; }
LL dijkstra(void) {
	LL D[100][100];
	int dx[]={-3, -2, -1, 0, 1, 2, 3, 2, 1, 0, -1, -2, -1, 0, 1, 0}, dy[]={0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 0, -1};
	priority_queue<pair<LL, pair<int, int>>, vector<pair<LL, pair<int, int>>>, greater<pair<LL, pair<int, int>>>> pq;
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			D[i][j]=INF;
	pq.push({0, {0, 0}});
	D[0][0]=0;
	while(!pq.empty()) {
		LL curd=pq.top().first;
		int curx=pq.top().second.first;
		int cury=pq.top().second.second;
		pq.pop();
		if(curd<D[curx][cury])
			continue;
		int over=abs(curx-(N-1))+abs(cury-(N-1));
		if(over<3&&curd+T*over<D[N-1][N-1])
			D[N-1][N-1]=curd+T*over;
		for(int i=0 ; i<16 ; i++) {
			int nx=curx+dx[i];
			int ny=cury+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=N)
				continue;
			LL nd=curd+arr[nx][ny]+3*T;
			if(nd<D[nx][ny]) {
				D[nx][ny]=nd;
				pq.push({nd, {nx, ny}});
			}
		}
	}
	return D[N-1][N-1];
}

int main(void) {
	scanf("%d%d", &N, &T);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			scanf("%d", &arr[i][j]);
	printf("%lld", dijkstra());
	return 0;
}
