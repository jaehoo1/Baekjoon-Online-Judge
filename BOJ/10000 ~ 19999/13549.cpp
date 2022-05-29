# include <cstdio>
# include <queue>
# define	INF	2147483647

using namespace std;

int N, D[200002];

void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(D, D+200002, INF);
	D[s]=0;
	pq.push({0, s});
	while(!pq.empty()) {
		int dist=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(D[cur]<dist)continue;
		int cost=dist;
		if(cur*2<200002)
			if(cost<D[cur*2]) {
				D[cur*2]=cost;
				pq.push({cost, cur*2});
			}
		cost++;
		if(cur-1>=0)
			if(cost<D[cur-1]) {
				D[cur-1]=cost;
				pq.push({cost, cur-1});
			}
		if(cur+1<200002)
			if(cost<D[cur+1]) {
				D[cur+1]=cost;
				pq.push({cost, cur+1});
			}
	}
}

int main(void) {
	int K;
	scanf("%d%d", &N, &K);
	dijkstra(N);
	printf("%d", D[K]);
	return 0;
}
