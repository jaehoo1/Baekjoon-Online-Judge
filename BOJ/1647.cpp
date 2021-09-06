# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int parent[100001];

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
	vector<pair<int, pair<int, int>>> G;
	int N, M, A, B, C, cost=0, last;
	scanf("%d%d", &N, &M);
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
			cost+=G[i].first;
			last=G[i].first;
		}
	printf("%d", cost-last);
	return 0;
}
