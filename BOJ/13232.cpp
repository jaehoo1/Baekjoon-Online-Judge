# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

typedef struct { int node, num; }data;

vector<int> G[5001], RG[5001], SCC[5000];
vector<data> arr;
bool visited[5002];
int cnt;

void dfs(int n) {
	visited[n]=true;
	for(int i=0 ; i<G[n].size() ; i++)
		if(!visited[G[n][i]])
			dfs(G[n][i]);
	arr.push_back({n, cnt++});
}
void rdfs(int n, int idx) {
	visited[n]=true;
	for(int i=0 ; i<RG[n].size() ; i++)
		if(!visited[RG[n][i]])
			rdfs(RG[n][i], idx);
	SCC[idx].push_back(n);
}
bool datacmp(const data &a, const data &b) { return a.num>b.num; }

int main(void) {
	int D, L, max=0;
	scanf("%d%d", &D, &L);
	for(int i=0 ; i<L ; i++) {
		int A, B;
		scanf("%d%d", &A, &B);
		G[A].push_back(B);
		RG[B].push_back(A);
	}
	for(int i=1 ; i<=D ; i++)
		if(!visited[i])
			dfs(i);
	sort(arr.begin(), arr.end(), datacmp);
	fill(visited, visited+D+1, false);
	cnt=0;
	for(int i=0 ; i<arr.size() ; i++)
		if(!visited[arr[i].node])
			rdfs(arr[i].node, cnt++);
	for(int i=0 ; i<cnt ; i++)
		if(SCC[i].size()>max)
			max=SCC[i].size();
	printf("%d", max);
	return 0;
}
