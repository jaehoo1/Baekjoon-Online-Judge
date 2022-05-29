# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

int N, in[1001], res[1001];
vector<int> G[1001];

void tsort(void) {
	queue<int> q;
	int cou=1;
	for(int i=1 ; i<=N ; i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			int cur=q.front();
			q.pop();
			res[cur]=cou;
			for(int i=0 ; i<G[cur].size() ; i++)
				if(!--in[G[cur][i]])
					q.push(G[cur][i]);
		}
		cou++;
	}
}

int main(void) {
	int M, A, B;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &A, &B);
		G[A].push_back(B);
		in[B]++;
	}
	tsort();
	for(int i=1 ; i<=N ; i++)
		printf("%d ", res[i]);
	return 0;
}
