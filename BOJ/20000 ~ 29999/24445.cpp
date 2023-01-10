# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

vector<int> G[100001];
int visit[100001];

bool cmp(const int &a, const int &b) { return a>b; }

void bfs(int start) {
	bool visited[100001]={false, };
	queue<int> q;
	int cou=1;
	visited[start]=true;
	q.push(start);
	while(!q.empty()) {
		int cur=q.front();
		visit[cur]=cou++;
		q.pop();
		for(int next : G[cur])
			if(!visited[next]) {
				visited[next]=true;
				q.push(next);
			}
	}
}

int main(void) {
	int N, M, R, u, v;
	scanf("%d%d%d", &N, &M, &R);
	while(M--) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1 ; i<=N ; i++)
		sort(G[i].begin(), G[i].end(), cmp);
	bfs(R);
	for(int i=1 ; i<=N ; i++)
		printf("%d\n", visit[i]);
	return 0;
}