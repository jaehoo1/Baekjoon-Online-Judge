# include <iostream>
# include <algorithm>
# include <unordered_map>

using namespace std;

typedef struct { int s, d, c; }edge;

int parent[200];

void init(int n) {
	for(int i=0 ; i<n ; i++)
		parent[i]=i;
}
int find(int x) { return x==parent[x]?x:parent[x]=find(parent[x]); }
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)
		parent[b]=a;
	else
		parent[a]=b;
}
bool edgecmp(const edge &a, const edge &b) { return a.c>b.c; }

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, r, node;
	string a, b;
	edge arr[19900];
	for(int x=1 ; cin>>n>>r ; x++) {
		if(!n&&!r)
			break;
		node=0;
		unordered_map<string, int> um;
		init(n);
		for(int i=0 ; i<r ; i++) {
			cin>>a>>b>>arr[i].c;
			if(um.find(a)==um.end())
				um[a]=node++;
			if(um.find(b)==um.end())
				um[b]=node++;
			arr[i].s=um[a];
			arr[i].d=um[b];
		}
		sort(arr, arr+r, edgecmp);
		cin>>a>>b;
		for(int i=0 ; i<r ; i++) {
			if(find(arr[i].s)!=find(arr[i].d))
				union_set(arr[i].s, arr[i].d);
			if(find(um[a])==find(um[b])) {
				cout<<"Scenario #"<<x<<'\n'<<arr[i].c<<" tons"<<'\n'<<'\n';
				break;
			}
		}
	}
	return 0;
}