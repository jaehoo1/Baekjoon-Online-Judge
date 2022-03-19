# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

typedef struct { int s, d, c; }edge;

bool cmp(const edge &a, const edge &b) { return a.c<b.c; }

int parent[1001];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)
		parent[b]=a;
	else
		parent[a]=b;
}

int main(void) {
	char c;
	int N, M, u, v, d, res=0;
	bool gender[1001]={false, };
	vector<edge> e;
	scanf("%d%d", &N, &M);
	getchar();
	for(int i=1 ; i<=N ; i++) {
		scanf("%c", &c);
		getchar();
		if(c=='W')
			gender[i]=true;
		parent[i]=i;
	}
	while(M--) {
		scanf("%d%d%d", &u, &v, &d);
		if(gender[u]==gender[v])
			continue;
		e.push_back({u, v, d});
	}
	sort(e.begin(), e.end(), cmp);
	for(int i=0 ; i<e.size() ; i++)
		if(find(e[i].s)!=find(e[i].d)) {
			union_set(e[i].s, e[i].d);
			res+=e[i].c;
		}
	for(int i=1 ; i<=N ; i++)
		if(find(1)!=find(i)) {
			puts("-1");
			return 0;
		}
	printf("%d", res);
	return 0;
}
