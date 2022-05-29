# include <cstdio>
# include <vector>
# include <algorithm>
# include <cmath>

using namespace std;

typedef struct {
	double x, y;
	int idx;
}pos;

int parent[101];

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
double dist(pos a, pos b) { return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2)); }

int main(void) {
	int n;
	double cost=0;
	pos arr[100];
	vector<pair<double, pair<int, int>>> G;
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++)
		parent[i]=i;
	for(int i=1 ; i<=n ; i++) {
		scanf("%lf%lf", &arr[i].x, &arr[i].y);
		arr[i].idx=i;
	}
	for(int i=1 ; i<=n-1 ; i++)
		for(int j=i+1 ; j<=n ; j++)
			G.push_back({dist(arr[i], arr[j]), {arr[i].idx, arr[j].idx}});
	sort(G.begin(), G.end());
	for(int i=0 ; i<G.size() ; i++)
		if(find(G[i].second.first)!=find(G[i].second.second)) {
			union_set(G[i].second.first, G[i].second.second);
			cost+=G[i].first;
		}
	printf("%lf", cost);
	return 0;
}
