# include <cstdio>
# include <queue>
# include <cstring>

using namespace std;

int G[101], D[101];

void bfs(int start) {
	bool visited[101]={false, };
	queue<int> q;
	memset(D, 0, sizeof(D));
	D[start]=0;
	visited[start]=true;
	q.push(start);
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		for(int i=1 ; i<=6 ; i++) {
			int dest=cur+i;
			if(dest>100)
				continue;
			if(G[dest])
				dest=G[dest];
			if(!D[dest]) {
				D[dest]=D[cur]+1;
				q.push(dest);
			}
		}
	}
}

int main(void) {
	int N, M, x, y;
	scanf("%d%d", &N, &M);
	while(N--) {
		scanf("%d%d", &x, &y);
		G[x]=y;
	}
	while(M--) {
		scanf("%d%d", &x, &y);
		G[x]=y;
	}
	bfs(1);
	printf("%d", D[100]);
	return 0;
}
