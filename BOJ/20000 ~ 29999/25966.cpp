# include <cstdio>
# include <vector>

using namespace std;

int main(void) {
	int N, M, q, cmd, num, i, j, k;
	vector<vector<int>> arr;
	scanf("%d%d%d", &N, &M, &q);
	for(int i=0 ; i<N ; i++) {
		vector<int> v;
		for(int j=0 ; j<M ; j++) {
			scanf("%d", &num);
			v.push_back(num);
		}
		arr.push_back(v);
	}
	while(q--) {
		scanf("%d%d%d", &cmd, &i, &j);
		if(!cmd) {
			scanf("%d", &k);
			arr[i][j]=k;
		} else
			arr[i].swap(arr[j]);
	}
	for(int i=0 ; i<N ; i++) {
		for(j=0 ; j<M ; j++)
			printf("%d ", arr[i][j]);
		puts("");
	}
	return 0;
}