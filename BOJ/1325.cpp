# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

vector<int> G[10001];

int bfs(int start) {
	queue<int> q;
	bool visited[10001]={false, };
	int cou=1;
	visited[start]=true;
	q.push(start);
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		for(int i=0 ; i<G[cur].size() ; i++)
			if(!visited[G[cur][i]]) {
				visited[G[cur][i]]=true;
				q.push(G[cur][i]);
				cou++;
			}
	}
	return cou;
}

int main(void) {
	int N, M, A, B, res[10001], max=0;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &A, &B);
		G[B].push_back(A);
	}
	for(int i=1 ; i<=N ; i++) {
		res[i]=bfs(i);
		if(res[i]>max)
			max=res[i];
	}
	for(int i=1 ; i<=N ; i++)
		if(res[i]==max)
			printf("%d ", i);
	return 0;
}
