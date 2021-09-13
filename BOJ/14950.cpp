# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int parent[10001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)parent[b]=a;
	else	parent[a]=b;
}

int main(void) {
	int N, M, t, T=0, cost=0, A, B, C;
	vector<pair<int, pair<int, int>>> G;
	scanf("%d%d%d", &N, &M, &t);
	for(int i=1 ; i<=N ; i++)
		parent[i]=i;
	while(M--) {
		scanf("%d%d%d", &A, &B, &C);
		G.push_back({C, {A, B}});
	}
	sort(G.begin(), G.end());
	for(int i=0 ; i<G.size() ; i++)
		if(find(G[i].second.first)!=find(G[i].second.second)) {
			union_set(G[i].second.first, G[i].second.second);
			cost+=G[i].first+T;
			T+=t;
		}
	printf("%d", cost);
	return 0;
}
