# include <iostream>
# include <unordered_map>
# include <string>

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
	if(a<b) {
		parent[b]=a;
		size[a]+=size[b];
	} else {
		parent[a]=b;
		size[b]+=size[a];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, F, A, B;
	cin>>T;
	while(T--) {
		unordered_map<string, int> um;
		string a, b;
		int num=1;
		cin>>F;
		while(F--) {
			cin>>a>>b;
			if(!um[a]) {
				um[a]=num;
				parent[num]=num;
				size[num++]=1;
			}
			if(!um[b]) {
				um[b]=num;
				parent[num]=num;
				size[num++]=1;
			}
			A=um[a];
			B=um[b];
			if(find(A)!=find(B))
				union_set(A, B);
			cout<<size[find(A)]<<'\n';
		}
	}
	return 0;
}
