# include <cstdio>
# include <algorithm>

using namespace std;

int main(void) {
	int n, A[4000], B[4000], C[4000], D[4000], sumCD[16000000];
	long long cou=0;
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++)
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			sumCD[i*n+j]=C[i]+D[j];
	sort(sumCD, sumCD+n*n);
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++) {
			int sumAB=A[i]+B[j];
			pair<int*, int*> p=equal_range(sumCD, sumCD+n*n, -sumAB);
			cou+=distance(p.first, p.second);
		}
	printf("%lld", cou);
	return 0;
}