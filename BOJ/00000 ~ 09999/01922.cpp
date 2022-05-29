# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int parent[1001];

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
	int N, M, a, b, c, cost=0;
	vector<pair<int, pair<int, int>>> G;
	scanf("%d%d", &N, &M);
	for(int i=1 ; i<=N ; i++)
		parent[i]=i;
	while(M--) {
		scanf("%d%d%d", &a, &b, &c);
		if(a==b)continue;
		G.push_back({c, {a, b}});
	}
	sort(G.begin(), G.end());
	for(int i=0 ; i<G.size() ; i++)
		if(find(G[i].second.first)!=find(G[i].second.second)) {
			union_set(G[i].second.first, G[i].second.second);
			cost+=G[i].first;
		}
	printf("%d", cost);
	return 0;
}
