# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

vector<int> G[300001];

int bfs(int S, int E) {
	bool visited[300001]={false, };
	queue<int> q;
	int cou=0;
	visited[S]=true;
	q.push(S);
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			q.pop();
			if(cur==E)
				return cou;
			if(cur+1<=300000&&!visited[cur+1]) {
				visited[cur+1]=true;
				q.push(cur+1);
			}
			if(cur-1>0&&!visited[cur-1]) {
				visited[cur-1]=true;
				q.push(cur-1);
			}
			for(int i=0 ; i<G[cur].size() ; i++)
				if(!visited[G[cur][i]]) {
					visited[G[cur][i]]=true;
					q.push(G[cur][i]);
				}
		}
		cou++;
	}
}

int main(void) {
	int N, M, S, E, x, y;
	scanf("%d%d%d%d", &N, &M, &S, &E);
	while(M--) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	printf("%d", bfs(S, E));
	return 0;
}