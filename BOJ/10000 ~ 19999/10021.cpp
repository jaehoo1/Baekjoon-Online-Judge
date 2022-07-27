# include <cstdio>
# include <vector>
# include <tuple>
# include <algorithm>

using namespace std;

int parent[2000];

int dist(pair<int, int> &a, pair<int, int> &b) { return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second); }
int find(int x) {
	if(x==parent[x])
		return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)
		parent[b]=a;
	else
		parent[a]=b;
}

int main(void) {
	int N, C, cost=0, cou=0;
	pair<int, int> pos[2000];
	vector<tuple<int, int, int>> edge;
	scanf("%d%d", &N, &C);
	for(int i=0 ; i<N ; i++) {
		parent[i]=i;
		scanf("%d%d", &pos[i].first, &pos[i].second);
	}
	for(int i=0 ; i<N-1 ; i++)
		for(int j=1 ; j<N ; j++)
			edge.push_back(make_tuple(dist(pos[i], pos[j]), i, j));
	sort(edge.begin(), edge.end());
	for(int i=0 ; i<edge.size() ; i++)
		if(find(get<1>(edge[i]))!=find(get<2>(edge[i]))&&get<0>(edge[i])>=C) {
			union_set(get<1>(edge[i]), get<2>(edge[i]));
			cost+=get<0>(edge[i]);
			cou++;
		}
	printf("%d", cou==N-1?cost:-1);
	return 0;
}