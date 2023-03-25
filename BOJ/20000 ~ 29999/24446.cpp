# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

int D[100001];
vector<int> G[100001];

void bfs(int start) {
	bool visited[100001]={false, };
	queue<int> q;
	int depth=0;
	visited[start]=true;
	D[start]=depth;
	q.push(start);
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			D[cur]=depth;
			q.pop();
			for(int i=0 ; i<G[cur].size() ; i++) {
				if(visited[G[cur][i]])
					continue;
				visited[G[cur][i]]=true;
				q.push(G[cur][i]);
			}
		}
		depth++;
	}
}

int main(void) {
	int N, M, R, u, v;
	scanf("%d%d%d", &N, &M, &R);
	fill(D, D+N+1, -1);
	while(M--) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs(R);
	for(int i=1 ; i<=N ; i++)
		printf("%d\n", D[i]);
	return 0;
}