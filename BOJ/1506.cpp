# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

typedef struct { int node, num; }data;

int N, cnt;
vector<int> G[100], RG[100], SCC[100];
bool visited[101];
data arr[100];

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

int main(void) {
	int cost[100], res=0;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		scanf("%d", &cost[i]);
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++) {
			int temp;
			scanf("%1d", &temp);
			if(temp&&i!=j) {
				G[i].push_back(j);
				RG[j].push_back(i);
			}
		}
	for(int i=0 ; i<N ; i++)
		if(!visited[i])
			dfs(i);
	sort(arr, arr+N, datacmp);
	fill(visited, visited+N, false);
	cnt=0;
	for(int i=0 ; i<N ; i++)
		if(!visited[arr[i].node])
			rdfs(arr[i].node, cnt++);
	for(int i=0 ; i<cnt ; i++) {
		int min=1000000;
		for(int j=0 ; j<SCC[i].size() ; j++)
			if(cost[SCC[i][j]]<min)
				min=cost[SCC[i][j]];
		res+=min;
	}
	printf("%d", res);
	return 0;
}
