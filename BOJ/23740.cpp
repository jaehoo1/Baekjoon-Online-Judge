# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

typedef struct { int S, E, C; }line;

bool linecmp(const line &a, const line &b) {
	if(a.S==b.S)
		return a.E<b.E;
	return a.S<b.S;
}

int main(void) {
	int N;
	vector<line> v;
    line arr[200000], temp;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		scanf("%d%d%d", &arr[i].S, &arr[i].E, &arr[i].C);
	sort(arr, arr+N, linecmp);
	temp=arr[0];
	for(int i=1 ; i<N ; i++)
		if(temp.E>=arr[i].S) {
			temp.E=max(temp.E, arr[i].E);
			temp.C=min(temp.C, arr[i].C);
		} else {
			v.push_back(temp);
			temp=arr[i];
		}
	v.push_back(temp);
	printf("%d\n", v.size());
	for(int i=0 ; i<v.size() ; i++)
		printf("%d %d %d\n", v[i].S, v[i].E, v[i].C);
	return 0;
}
