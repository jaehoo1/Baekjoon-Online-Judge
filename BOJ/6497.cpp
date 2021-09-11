# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int parent[200000];

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
	int m, n, x, y, z, cost, sum;
	while(scanf("%d%d", &m, &n)) {
		if(!m&&!n)
			break;
		cost=0;	sum=0;
		vector<pair<int, pair<int, int>>> G;
		for(int i=0 ; i<m ; i++)
			parent[i]=i;
		while(n--) {
			scanf("%d%d%d", &x, &y, &z);
			G.push_back({z, {x, y}});
			sum+=z;
		}
		sort(G.begin(), G.end());
		for(int i=0 ; i<G.size() ; i++)
			if(find(G[i].second.first)!=find(G[i].second.second)) {
				union_set(G[i].second.first, G[i].second.second);
				cost+=G[i].first;
			}
		printf("%d\n", sum-cost);
	}
	return 0;
}
