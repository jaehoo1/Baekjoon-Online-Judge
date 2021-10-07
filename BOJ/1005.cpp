# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

int N, D[1001], in[1001], dist[1002];
vector<int> G[1001];

void tsort(int end) {
	queue<int> q;
	fill(dist+1, dist+1+N, -1);
	for(int i=1 ; i<=N ; i++)
		if(!in[i]) {
			q.push(i);
			dist[i]=D[i];
		}
	while(in[end]) {
		int cur=q.front();
		q.pop();
		for(int i=0 ; i<G[cur].size() ; i++) {
			int next=G[cur][i];
			in[next]--;
			if(!in[next])
				q.push(next);
			int cost=dist[cur]+D[next];
			if(cost>dist[next])
				dist[next]=cost;
		}
	}
}

int main(void) {
	int T, K, X, Y, W;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		for(int i=1 ; i<=N ; i++) {
			G[i].clear();
			in[i]=0;
			scanf("%d", &D[i]);
		}
		while(K--) {
			scanf("%d%d", &X, &Y);
			G[X].push_back(Y);
			in[Y]++;
		}
		scanf("%d", &W);
		tsort(W);
		printf("%d\n", dist[W]);
	}
	return 0;
}
