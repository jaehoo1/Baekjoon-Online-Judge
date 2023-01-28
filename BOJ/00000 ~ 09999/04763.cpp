# include <iostream>
# include <cmath>
# include <string>
# include <algorithm>
# include <unordered_map>

using namespace std;

typedef struct {
	int s, d;
	double c;
}edge;

int parent[100000];

bool edgecmp(const edge &a, const edge &b) { return a.c<b.c; }
int find(int x) { return x==parent[x]?x:parent[x]=find(parent[x]); }
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)
		parent[b]=a;
	else
		parent[a]=b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	double cable, dist, sum=0;
	int N, M;
	string s, A, B;
	edge arr[100000];
	unordered_map<string, int> um;
	cin>>cable>>N;
	for(int i=0 ; i<N ; i++) {
		cin>>s;
		um[s]=i;
		parent[i]=i;
	}
	cin>>M;
	for(int i=0 ; i<M ; i++) {
		cin>>A>>B>>dist;
		arr[i].s=um[A];
		arr[i].d=um[B];
		arr[i].c=dist;
	}
	sort(arr, arr+M, edgecmp);
	for(int i=0 ; i<M ; i++) {
		if(find(arr[i].s)==find(arr[i].d))
			continue;
		union_set(arr[i].s, arr[i].d);
		sum+=arr[i].c;
	}
	if(sum<=cable)
		cout<<"Need "<<sum<<" miles of cable";
	else
		cout<<"Not enough cable";
	return 0;
}