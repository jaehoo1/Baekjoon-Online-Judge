# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

vector<int> G[101];
int n, A, B, cou;
bool visited[101];

int bfs(void) {
	queue<int> q;
	q.push(A);
	visited[A]=true;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			q.pop();
			if(cur==B)
				return cou;
			for(int i=0 ; i<G[cur].size() ; i++)
				if(!visited[G[cur][i]]) {
					visited[G[cur][i]]=true;
					q.push(G[cur][i]);
				}
		}
		cou++;
	}
	return -1;
}

int main(void) {
	int m, x, y;
	scanf("%d%d%d", &n, &A, &B);
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	printf("%d", bfs());
	return 0;
}
