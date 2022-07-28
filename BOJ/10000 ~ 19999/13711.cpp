# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
	int N, A[100001], B[100001], C[100001], pos;
	vector<int> v;
	scanf("%d", &N);
	for(int i=1 ; i<=N ; i++) {
		scanf("%d", &pos);
		A[pos]=i;
	}
	for(int i=1 ; i<=N ; i++)
		scanf("%d", &B[i]);
	for(int i=1 ; i<=N ; i++)
		C[i]=A[B[i]];
	v.push_back(C[1]);
	for(int i=2 ; i<=N ; i++)
		if(C[i]>v.back())
			v.push_back(C[i]);
		else {
			vector<int>::iterator iter=lower_bound(v.begin(), v.end(), C[i]);
			*iter=C[i];
		}
	printf("%d", v.size());
	return 0;
}