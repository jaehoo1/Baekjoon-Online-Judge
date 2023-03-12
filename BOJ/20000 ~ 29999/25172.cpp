# include <cstdio>
# include <vector>
# include <unordered_set>

using namespace std;

vector<int> G[200001];

int parent[200001], size[200001];

int find(int x) {
	if(x==parent[x])
		return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b) {
		size[a]+=size[b];
		parent[b]=a;
	} else {
		size[b]+=size[a];
		parent[a]=b;
	}
}

int main(void) {
	int N, M, a, b, query[200001];
	unordered_set<int> us;
	bool connected[200001]={false, };
	scanf("%d%d", &N, &M);
	for(int i=1 ; i<=N ; i++) {
		parent[i]=i;
		size[i]=1;
	}
	while(M--) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0 ; i<N ; i++)
		scanf("%d", &query[i]);
	for(int i=N-1 ; i>=0 ; i--) {
		us.insert(query[i]);
		for(int j=0 ; j<G[query[i]].size() ; j++) {
			if(us.find(G[query[i]][j])==us.end()||find(query[i])==find(G[query[i]][j]))
				continue;
			union_set(query[i], G[query[i]][j]);
		}
		if(size[find(query[i])]==us.size())
			connected[i]=true;
	}
	for(int i=0 ; i<N ; i++)
		puts(connected[i]?"CONNECT":"DISCONNECT");
	puts("DISCONNECT");
	return 0;
}