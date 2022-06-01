# include <cstdio>
# include <unordered_set>

using namespace std;

unordered_set<int> us;

int N, arr[20];

void dfs(int depth, int sum) {
	if(depth>0&&sum)
		us.insert(sum);
	if(depth==N)
		return;
	dfs(depth+1, sum+arr[depth]);
	dfs(depth+1, sum);
}

int main(void) {
	int M=0;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		scanf("%d", &arr[i]);
		M+=arr[i];
	}
	dfs(0, 0);
	printf("%d", M-us.size());
	return 0;
}