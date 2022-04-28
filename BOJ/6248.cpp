# include <cstdio>
# include <queue>
# define	INF	1e9

using namespace std;

int N, G[1001][1001];

int dijkstra(int start) {
	int D[1002], max=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(D, D+N+1, INF);
	D[start]=0;
	pq.push({0, start});
	while(!pq.empty()) {
		int cost=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(D[cur]<cost)
			continue;
		for(int i=1 ; i<=N ; i++)
			if(G[cur][i]&&cost+G[cur][i]<D[i]) {
				D[i]=cost+G[cur][i];
				pq.push({D[i], i});
			}
	}
	for(int i=1 ; i<=N ; i++)
		if(i!=start&&D[i]>max)
			max=D[i];
	return max;
}

int main(void) {
	int M, X, A, B, T;
	scanf("%d%d%d", &N, &M, &X);
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=N ; j++)
			G[i][j]=INF;
	while(M--) {
		scanf("%d%d%d", &A, &B, &T);
		if(T<G[A][B])
			G[A][B]=G[B][A]=T;
	}
	printf("%d", 2*dijkstra(X));
	return 0;
}
