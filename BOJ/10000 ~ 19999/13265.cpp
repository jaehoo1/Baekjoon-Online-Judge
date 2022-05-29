# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

int n;
bool visited[1002], color[1002];

void dfs(vector<int> G[1001], int node, int depth) {
	visited[node]=true;
	color[node]=depth%2;
	for(int i=0 ; i<G[node].size() ; i++)
		if(!visited[G[node][i]])
			dfs(G, G[node][i], depth+1);
}
bool bfs(vector<int> G[1001], int start) {
	bool colorflag=false;
	queue<int> q;
	visited[start]=true;
	q.push(start);
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			q.pop();
			if(colorflag!=color[cur])
				return false;
			for(int i=0 ; i<G[cur].size() ; i++)
				if(!visited[G[cur][i]]) {
					visited[G[cur][i]]=true;
					q.push(G[cur][i]);
				}
		}
		colorflag=!colorflag;
	}
	return true;
}

int main(void) {
	bool canpaint;
	int T, m, x, y;
	scanf("%d", &T);
	while(T--) {
		vector<int> G[1001];
		canpaint=true;
		scanf("%d%d", &n, &m);
		fill(visited, visited+n+1, false);
		while(m--) {
			scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for(int i=1 ; i<=n ; i++)
			if(!visited[i])
				dfs(G, i, 0);
		fill(visited, visited+n+1, false);
		for(int i=1 ; i<=n ; i++)
			if(!visited[i]&&!bfs(G, i)) {
				canpaint=false;
				break;
			}
		puts(canpaint?"possible":"impossible");
	}
	return 0;
}
