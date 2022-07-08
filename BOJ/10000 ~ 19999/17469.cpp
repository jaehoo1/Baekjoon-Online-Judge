# include <cstdio>
# include <unordered_set>
# include <vector>

using namespace std;

int parent[100001];
unordered_set<int> color[100001];

int find(int x) {
	if(x==parent[x])
		return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(color[a].size()<color[b].size()) {
		parent[a]=b;
		color[b].insert(color[a].begin(), color[a].end());
		color[a]=unordered_set<int>();
	} else {
		parent[b]=a;
		color[a].insert(color[b].begin(), color[b].end());
		color[b]=unordered_set<int>();
	}
}

int main(void) {
	int N, Q, p[100001], c;
	pair<int, int> query[1099999];
	vector<int> answer;
	scanf("%d%d", &N, &Q);
	for(int i=1 ; i<=N ; i++)
		parent[i]=i;
	for(int i=2 ; i<=N ; i++)
		scanf("%d", &p[i]);
	for(int i=1 ; i<=N ; i++) {
		scanf("%d", &c);
		color[i].insert(c);
	}
	for(int i=0 ; i<N+Q-1 ; i++)
		scanf("%d%d", &query[i].first, &query[i].second);
	for(int i=N+Q-2 ; i>=0 ; i--)
		if(query[i].first==1)
			union_set(query[i].second, p[query[i].second]);
		else if(query[i].first==2)
			answer.push_back(color[find(query[i].second)].size());
	for(int i=answer.size()-1 ; i>=0 ; i--)
		printf("%d\n", answer[i]);
	return 0;
}