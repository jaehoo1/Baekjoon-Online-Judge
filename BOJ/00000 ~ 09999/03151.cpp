# include <cstdio>
# include <algorithm>

using namespace std;

int main(void) {
	int N, A[10000], sum;
	long long cou=0;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		scanf("%d", &A[i]);
	sort(A, A+N);
	for(int i=0 ; i<N-2 ; i++)
		for(int j=i+1 ; j<N-1 ; j++) {
			sum=-A[i]-A[j];
			pair<int*, int*> p=equal_range(A+j+1, A+N, sum);
			cou+=distance(p.first, p.second);
		}
	printf("%lld", cou);
	return 0;
}