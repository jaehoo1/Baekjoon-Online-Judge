# include <cstdio>
# include <queue>

using namespace std;

bool visited[20001];
int dist[20001];
vector<int> G[20001];

void bfs(int s) {
	int cou=1;
	queue<int> q;
	visited[s]=true;
	dist[s]=0;
	q.push(s);
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			q.pop();
			for(int i=0 ; i<G[cur].size() ; i++)
				if(!visited[G[cur][i]]) {
					visited[G[cur][i]]=true;
					dist[G[cur][i]]=cou;
					q.push(G[cur][i]);
				}
		}
		cou++;
	}
}

int main(void) {
	int N, M, A, B, num, max=0, cou=0;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &A, &B);
		G[A].push_back(B);
		G[B].push_back(A);
	}
	bfs(1);
	for(int i=1 ; i<=N ; i++)
		if(dist[i]>max) {
			max=dist[i];
			num=i;
		}
	for(int i=1 ; i<=N ; i++)
		if(dist[i]==max)
			cou++;
	printf("%d %d %d", num, max, cou);
	return 0;
}
