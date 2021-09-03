# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>
# define	INF	2147483647

using namespace std;

int n, D[1001], parent[1001];
vector<pair<int, int>> G[1001];

void dijkstra(int s) {
	fill(D+1, D+n+1, INF);
	D[s]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	while(!pq.empty()) {
		int dist=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(D[cur]<dist)continue;
		for(int i=0 ; i<G[cur].size() ; i++) {
			int cost=dist+G[cur][i].second;
			if(cost<D[G[cur][i].first]) {
				D[G[cur][i].first]=cost;
				pq.push({cost, G[cur][i].first});
				parent[G[cur][i].first]=cur;
			}
		}
	}
}

int main(void) {
	int m, start, end, a, b, c;
	scanf("%d%d", &n, &m);
	while(m--) {
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({b, c});
	}
	scanf("%d%d", &start, &end);
	dijkstra(start);
	printf("%d\n", D[end]);
	vector<int> parent_arr;
	while(end) {
		parent_arr.push_back(end);
		end=parent[end];
		if(end==start)break;
	}
	parent_arr.push_back(start);
	reverse(parent_arr.begin(), parent_arr.end());
	printf("%d\n", parent_arr.size());
	for(int i=0 ; i<parent_arr.size() ; i++)
		printf("%d ", parent_arr[i]);
	return 0;
}
