# include <cstdio>
# include <vector>
# include <unordered_set>

using namespace std;

int parent[200001], size[200001];

int find(int x) {
	if(x==parent[x])
		return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a==b)
		return;
	else if(a<b) {
		size[a]+=size[b];
		parent[b]=a;
	} else {
		size[b]+=size[a];
		parent[a]=b;
	}
}

int main(void) {
	int N, M, a, b, close[200000];
	unordered_set<int> opened;
	bool connected[200000];
	vector<int> G[200001];
	scanf("%d%d", &N, &M);
	for(int i=1 ; i<=N ; i++) {
		parent[i]=i;
		size[i]=1;
	}
	for(int i=0 ; i<M ; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0 ; i<N ; i++)
		scanf("%d", &close[i]);
	for(int i=N-1 ; i>=0 ; i--) {
		for(int j=0 ; j<G[close[i]].size() ; j++) {
			if(opened.find(G[close[i]][j])==opened.end())
				continue;
			union_set(close[i], G[close[i]][j]);
		}
		opened.insert(close[i]);
		connected[i]=size[find(close[i])]==N-i?true:false;
	}
	for(int i=0 ; i<N ; i++)
		puts(connected[i]?"YES":"NO");
	return 0;
}