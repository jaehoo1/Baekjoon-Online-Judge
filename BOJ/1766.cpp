# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

int N, in[32001];
vector<int> G[32001];

void tsort(void) {
	vector<int> res;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=1 ; i<=N ; i++)
		if(!in[i])
			pq.push(i);
	while(!pq.empty()) {
		int cur=pq.top();
		res.push_back(cur);
		pq.pop();
		for(int i=0 ; i<G[cur].size() ; i++) {
			in[G[cur][i]]--;
			if(!in[G[cur][i]])
				pq.push(G[cur][i]);
		}
	}
	for(int i=0 ; i<res.size() ; i++)
		printf("%d ", res[i]);
}

int main(void) {
	int M, A, B;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &A, &B);
		in[B]++;
		G[A].push_back(B);
	}
	tsort();
	return 0;
}
