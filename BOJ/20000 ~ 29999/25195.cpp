# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

vector<int> G[100001];
bool fanclub[100001];

bool bfs(void) {
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		if(fanclub[cur])
			continue;
		if(!G[cur].size())
			return true;
		for(int i=0 ; i<G[cur].size() ; i++)
			q.push(G[cur][i]);
	}
	return false;
}

int main(void) {
	int N, M, u, v, S, s;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	scanf("%d", &S);
	while(S--) {
		scanf("%d", &s);
		fanclub[s]=true;
	}
	puts(bfs()?"yes":"Yes");
	return 0;
}
