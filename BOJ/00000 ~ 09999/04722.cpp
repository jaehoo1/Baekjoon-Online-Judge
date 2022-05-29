# include <cstdio>
# include <cmath>
# include <vector>
# include <algorithm>

using namespace std;

typedef struct { int x, y, idx; }node;
typedef struct {
	int s, d;
	double c;
}edge;

int parent[1001];

int ufind(int x) {
	if(x==parent[x])return x;
	return parent[x]=ufind(parent[x]);
}
void umerge(int a, int b) {
	a=ufind(a);
	b=ufind(b);
	if(a<b)parent[b]=a;
	else	parent[a]=b;
}
double dist(node A, node B) {
	return sqrt(pow(A.x-B.x, 2)+pow(A.y-B.y, 2));
}
bool edgecmp(const edge &a, const edge &b) { return a.c<b.c; }

int main(void) {
	int N;
	node arr[1000];
	while(scanf("%d", &N)) {
		if(!N)
			break;
		for(int i=0 ; i<N ; i++) {
			scanf("%d%d", &arr[i].x, &arr[i].y);
			arr[i].idx=i;
			parent[i]=i;
		}
		vector<edge> G;
		for(int i=0 ; i<N-1 ; i++)
			for(int j=i+1 ; j<N ; j++) {
				G.push_back({i, j, dist(arr[i], arr[j])});
			}
		sort(G.begin(), G.end(), edgecmp);
		double res=0;
		for(int i=0 ; i<G.size() ; i++)
			if(ufind(G[i].s)!=ufind(G[i].d)) {
				res+=G[i].c;
				umerge(G[i].s, G[i].d);
			}
		printf("%lf\n", res);
	}
	return 0;
}
