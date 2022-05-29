# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

typedef struct { int node, num; }data;
typedef struct { int x, y; }edge;

vector<int> G[100001], RG[100001], SCC[100000];
int cnt, sc[100001];
bool visited[100002];
vector<data> arr;

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
	sc[n]=idx;
}
bool datacmp(const data &a, const data &b) { return a.num>b.num; }

int main(void) {
	int T, N, M;
	edge line[100000];
	scanf("%d", &T);
	while(T--) {
		int in[100000]={0, }, res=0;
		for(int i=0 ; i<cnt ; i++)
			SCC[i].clear();
		cnt=0;
		arr.clear();
		scanf("%d%d", &N, &M);
		for(int i=1 ; i<=N ; i++) {
			G[i].clear();
			RG[i].clear();
		}
		fill(visited, visited+N+1, false);
		for(int i=0 ; i<M ; i++) {
			scanf("%d%d", &line[i].x, &line[i].y);
			G[line[i].x].push_back(line[i].y);
			RG[line[i].y].push_back(line[i].x);
		}
		for(int i=1 ; i<=N ; i++)
			if(!visited[i])
				dfs(i);
		sort(arr.begin(), arr.end(), datacmp);
		fill(visited, visited+N+1, false);
		cnt=0;
		for(int i=0 ; i<arr.size() ; i++)
			if(!visited[arr[i].node])
				rdfs(arr[i].node, cnt++);
		for(int i=0 ; i<M ; i++)
			if(sc[line[i].x]!=sc[line[i].y])
				in[sc[line[i].y]]++;
		for(int i=0 ; i<cnt ; i++)
			if(!in[i])
				res++;
		printf("%d\n", res);
	}
	return 0;
}
