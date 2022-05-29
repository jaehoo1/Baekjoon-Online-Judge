# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

vector<pair<int, int>> G[1001];

int bfs(int start, int end) {
	int cost[1001];
	queue<int> q;
	bool visited[1001]={false, };
	visited[start]=true;
	cost[start]=0;
	q.push(start);
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		if(cur==end)
			break;
		for(int i=0 ; i<G[cur].size() ; i++) {
			int next=G[cur][i].first;
			if(!visited[next]) {
				visited[next]=true;
				cost[next]=cost[cur]+G[cur][i].second;
				q.push(next);
			}
		}
	}
	return cost[end];
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i=0 ; i<N-1 ; i++) {
		int src, dest, cost;
		scanf("%d%d%d", &src, &dest, &cost);
		G[src].push_back({dest, cost});
		G[dest].push_back({src, cost});
	}
	while(M--) {
		int src, dest;
		scanf("%d%d", &src, &dest);
		printf("%d\n", bfs(src, dest));
	}
	return 0;
}
