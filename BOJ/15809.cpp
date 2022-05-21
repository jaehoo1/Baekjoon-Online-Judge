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
void ally(int a, int b) {
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
void war(int a, int b) {
	a=find(a);
	b=find(b);
	if(size[a]<size[b]) {
		size[b]-=size[a];
		parent[a]=b;
	} else if(size[a]>size[b]) {
		size[a]-=size[b];
		parent[b]=a;
	} else {
		size[a]=size[b]=0;
		parent[a]=parent[b]=0;
	}
}

int main(void) {
	int N, M, i, O, P, Q;
	vector<int> v;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++) {
		scanf("%d", &size[i]);
		parent[i]=i;
	}
	while(M--) {
		scanf("%d%d%d", &O, &P, &Q);
		if(O==1)
			ally(P, Q);
		else if(O==2)
			war(P, Q);
	}
	for(i=1 ; i<=N ; i++)
		if(find(i)==i)
			v.push_back(size[i]);
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for(int i=0 ; i<v.size() ; i++)
		printf("%d ", v[i]);
	return 0;
}
