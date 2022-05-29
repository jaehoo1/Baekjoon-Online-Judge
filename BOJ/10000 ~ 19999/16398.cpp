# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int parent[1000];

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
	int N, num;
	long long cost=0;
	vector<pair<int, pair<int, int>>> G;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		parent[i]=i;
		for(int j=0 ; j<N ; j++) {
			scanf("%d", &num);
			if(i==j)continue;
			G.push_back({num, {i, j}});
		}
	}
	sort(G.begin(), G.end());
	for(int i=0 ; i<G.size() ; i++)
		if(find(G[i].second.first)!=find(G[i].second.second)) {
			union_set(G[i].second.first, G[i].second.second);
			cost+=G[i].first;
		}
	printf("%lld", cost);
	return 0;
}
