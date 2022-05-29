# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

vector<int> G[10001];
int N, in[10001], time[10001], dp[10001];

int tsort(void) {
	queue<int> q;
	int res=0;
	for(int i=1 ; i<=N ; i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		for(int i=0 ; i<G[cur].size() ; i++) {
			dp[G[cur][i]]=max(dp[G[cur][i]], dp[cur]+time[G[cur][i]]);
			if(!--in[G[cur][i]])
				q.push(G[cur][i]);
		}
	}
	for(int i=1 ; i<=N ; i++)
		if(dp[i]>res)
			res=dp[i];
	return res;
}

int main(void) {
	scanf("%d", &N);
	for(int i=1 ; i<=N ; i++) {
		int K, num;
		scanf("%d%d", &time[i], &K);
		dp[i]=time[i];
		while(K--) {
			scanf("%d", &num);
			G[num].push_back(i);
			in[i]++;
		}
	}
	printf("%d", tsort());
	return 0;
}
