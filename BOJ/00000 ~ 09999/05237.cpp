# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

bool bfs(vector<int> G[100], int n) {
	bool visited[100]={false, };
	queue<int> q;
	visited[0]=true;
	q.push(0);
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		for(int i=0 ; i<G[cur].size() ; i++) {
			int next=G[cur][i];
			if(!visited[next]) {
				visited[next]=true;
				q.push(next);
			}
		}
	}
	for(int i=0 ; i<n ; i++)
		if(!visited[i])
			return false;
	return true;
}

int main(void) {
	int t, n, k, a, b;
	scanf("%d", &t);
	while(t--) {
		vector<int> G[100];
		scanf("%d%d", &n, &k);
		while(k--) {
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		puts(bfs(G, n)?"Connected.":"Not connected.");
	}
	return 0;
}