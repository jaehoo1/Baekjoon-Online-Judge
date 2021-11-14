# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

typedef struct { int node, num; }data;

vector<int> G[10001], RG[10001], SCC[10001];
bool visited[10002];
int cnt;
data arr[10001];

void dfs(int n) {
	visited[n]=true;
	for(int i=0 ; i<G[n].size() ; i++)
		if(!visited[G[n][i]])
			dfs(G[n][i]);
	arr[cnt].node=n;
	arr[cnt].num=cnt+1;
	cnt++;
}
void rdfs(int n, int idx) {
	visited[n]=true;
	for(int i=0 ; i<RG[n].size() ; i++)
		if(!visited[RG[n][i]])
			rdfs(RG[n][i], idx);
	SCC[idx].push_back(n);
}
bool datacmp(const data &a, const data &b) { return a.num>b.num; }
bool vectorcmp(const vector<int> &a, const vector<int> &b) { return a[0]<b[0]; }

int main(void) {
	int V, E;
	scanf("%d%d", &V, &E);
	while(E--) {
		int A, B;
		scanf("%d%d", &A, &B);
		G[A].push_back(B);
		RG[B].push_back(A);
	}
	for(int i=1 ; i<=V ; i++)
		if(!visited[i])
			dfs(i);
	sort(arr, arr+V, datacmp);
	fill(visited, visited+V+1, false);
	cnt=0;
	for(int i=0 ; i<V ; i++)
		if(!visited[arr[i].node]) {
			rdfs(arr[i].node, cnt);
			sort(SCC[cnt].begin(), SCC[cnt].end());
			cnt++;
		}
	printf("%d\n", cnt);
	sort(SCC, SCC+cnt, vectorcmp);
	for(int i=0 ; i<cnt ; i++) {
		for(int j=0 ; j<SCC[i].size() ; j++)
			printf("%d ", SCC[i][j]);
		printf("-1\n");
	}
	return 0;
}
