# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

typedef struct { int d, c; }edge;

int parent[10001], N;
bool visited[10001];
vector<int> G[10001];

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
bool edgecmp(const edge &a, const edge &b) {
	if(a.c<b.c)return 1;
	return 0;
}
void dfs(int n) {
	visited[n]=true;
	for(int i=0 ; i<G[n].size() ; i++)
		if(!visited[G[n][i]]) {
			visited[G[n][i]]=true;
			dfs(G[n][i]);
		}
}

int main(void) {
	int M, k, cost=0;
	edge arr[10000];
	scanf("%d%d%d", &N, &M, &k);
	for(int i=0 ; i<N ; i++) {
		arr[i].d=i+1;
		scanf("%d", &arr[i].c);
	}
	sort(arr, arr+N, edgecmp);
	for(int i=1 ; i<=N ; i++)
		parent[i]=i;
	while(M--) {
		int v, w;
		scanf("%d%d", &v, &w);
		union_set(v, w);
		G[v].push_back(w);
		G[w].push_back(v);
	}
	for(int i=0 ; i<N ; i++) {
		if(find(0)!=find(arr[i].d))
			if(cost+arr[i].c<=k) {
				cost+=arr[i].c;
				union_set(0, arr[i].d);
				G[0].push_back(arr[i].d);
				G[arr[i].d].push_back(0);
			}
	}
	dfs(0);
	for(int i=0 ; i<=N ; i++)
		if(!visited[i]) {
			puts("Oh no");
			return 0;
		}
	printf("%d", cost);
	return 0;
}
