# include <cstdio>
# include <queue>

using namespace std;

pair<int, int> G[1001];

int bfs(int node) {
	queue<int> q;
	q.push(1);
	int cou=0;
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			q.pop();
			if(G[cur].first)
				q.push(G[cur].first);
			if(G[cur].second)
				q.push(G[cur].second);
		}
		cou++;
	}
	return cou;
}

int main(void) {
	int P, Cn, D1, D2;
	scanf("%d", &P);
	for(int i=1 ; i<P ; i++) {
		scanf("%d%d%d", &Cn, &D1, &D2);
		G[Cn].first=D1;
		G[Cn].second=D2;
	}
	printf("%d", bfs(1));
	return 0;
}