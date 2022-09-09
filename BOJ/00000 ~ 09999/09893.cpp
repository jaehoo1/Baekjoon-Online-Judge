# include <cstdio>
# include <vector>
# include <queue>
# include <tuple>
# define	INF	1e9

using namespace std;

int m;
vector<pair<int, int>> G[100];

int dijkstra(void) {
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	int L[101], C[101];
	fill(L, L+m, INF);
	fill(C, C+m, INF);
	L[0]=0;
	C[0]=0;
	pq.push(make_tuple(0, 0, 0));
	while(!pq.empty()) {
		int curlength=get<0>(pq.top());
		int curcost=get<1>(pq.top());
		int cur=get<2>(pq.top());
		pq.pop();
		for(int i=0 ; i<G[cur].size() ; i++) {
			int next=G[cur][i].first;
			int nextcost=curcost+G[cur][i].second;
			if((curlength+1==L[next]&&nextcost<C[next])||curlength+1<L[next]) {
				L[next]=curlength+1;
				C[next]=nextcost;
				pq.push(make_tuple(curlength+1, nextcost, next));
			}
		}
	}
	return C[1];
}

int main(void) {
	int n, s, d, c;
	scanf("%d%d", &m, &n);
	while(n--) {
		scanf("%d%d%d", &s, &d, &c);
		G[s].push_back({d, c});
	}
	printf("%d", dijkstra());
	return 0;
}