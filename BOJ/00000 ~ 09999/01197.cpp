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
	int V, E, A, B, C, res=0;
	vector<pair<int, pair<int, int>>> G;
	scanf("%d%d", &V, &E);
	for(int i=1 ; i<=V ; i++)
		parent[i]=i;
	for(int i=0 ; i<E ; i++) {
		scanf("%d%d%d", &A, &B, &C);
		G.push_back({C, {A, B}});
	}
	sort(G.begin(), G.end());
	for(int i=0 ; i<E ; i++)
		if(find(G[i].second.first)!=find(G[i].second.second)) {
			union_set(G[i].second.first, G[i].second.second);
			res+=G[i].first;
		}
	printf("%d", res);
	return 0;
}
