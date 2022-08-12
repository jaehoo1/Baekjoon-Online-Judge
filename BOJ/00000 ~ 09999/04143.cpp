# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

int parent[100000], size[100000];

void nodeinit(int n) {
	parent[n]=n;
	size[n]=1;
}
int find(int x) {
	if(x==parent[x])
		return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b) {
		parent[b]=a;
		size[a]+=size[b];
	} else {
		parent[a]=b;
		size[b]+=size[a];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n;
	string a, b;
	cin>>T;
	while(T--) {
		unordered_map<string, int> um;
		int cou=0;
		cin>>n;
		while(n--) {
			cin>>a>>b;
			if(um.find(a)==um.end()) {
				nodeinit(cou);
				um.insert({a, cou++});
			}
			if(um.find(b)==um.end()) {
				nodeinit(cou);
				um.insert({b, cou++});
			}
			if(find(um[a])!=find(um[b]))
				union_set(find(um[a]), find(um[b]));
			cout<<size[find(um[a])]<<'\n';
		}
	}
	return 0;
}