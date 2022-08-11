# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
	int N, arr[1000];
	vector<pair<int, int>> op;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	for(int i=0 ; i<N ; i++) {
		if(arr[i]==i+1)
			continue;
		int idx=i+1;
		while(i+1!=arr[idx])
			idx++;
		reverse(arr+i, arr+idx+1);
		op.push_back({i+1, idx+1});
	}
	printf("%d\n", op.size());
	for(int i=0 ; i<op.size() ; i++)
		printf("%d %d\n", op[i].first, op[i].second);
	return 0;
}