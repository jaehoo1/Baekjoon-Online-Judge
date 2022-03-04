# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

int N, dp[101][101], in[101];
vector<pair<int, int>> G[101];

void tsort(void) {
	queue<int> q;
	for(int i=1 ; i<N ; i++)
		if(!in[i]) {
			q.push(i);
			dp[i][i]++;
		}
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		for(int i=0 ; i<G[cur].size() ; i++) {
			for(int j=1 ; j<=N ; j++)
				if(dp[cur][j])
					dp[G[cur][i].first][j]+=dp[cur][j]*G[cur][i].second;
			if(!--in[G[cur][i].first])
				q.push(G[cur][i].first);
		}
	}
}

int main(void) {
	int M, X, Y, Z;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d%d", &X, &Y, &Z);
		G[Y].push_back({X, Z});
		in[X]++;
	}
	tsort();
	for(int i=1 ; i<=N ; i++)
		if(dp[N][i])
			printf("%d %d\n", i, dp[N][i]);
	return 0;
}
