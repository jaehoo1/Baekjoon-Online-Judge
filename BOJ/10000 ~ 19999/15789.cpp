# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int parent[100001], size[100001];

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
	int N, M, X, Y, C, H, K;
	vector<pair<int, int>> v;
	scanf("%d%d", &N, &M);
	for(int i=1 ; i<=N ; i++) {
		parent[i]=i;
		size[i]=1;
	}
	while(M--) {
		scanf("%d%d", &X, &Y);
		if(find(X)!=find(Y))
			union_set(X, Y);
	}
	scanf("%d%d%d", &C, &H, &K);
	for(int i=1 ; i<=N ; i++)
		if(find(i)==i)
			v.push_back({size[i], i});
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(int i=0 ; i<v.size()&&K ; i++) {
		if(find(v[i].second)==find(C)||find(v[i].second)==find(H))
			continue;
		union_set(find(C), v[i].second);
		K--;
	}
	printf("%d", size[find(C)]);
	return 0;
}