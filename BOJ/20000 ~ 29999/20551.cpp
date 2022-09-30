# include <cstdio>
# include <algorithm>

using namespace std;

int main(void) {
	int N, M, arr[200000], D, *ptr;
	scanf("%d%d", &N, &M);
	for(int i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+N);
	while(M--) {
		scanf("%d", &D);
		ptr=lower_bound(arr, arr+N, D);
		printf("%d\n", *ptr==D?ptr-arr:-1);
	}
	return 0;
}