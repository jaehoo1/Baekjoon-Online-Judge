# include <cstdio>
# include <algorithm>

using namespace std;

int n;
long long A[100000];

int query1(long long k) { return n-(lower_bound(A, A+n, k)-A); }
int query2(long long k) { return n-(upper_bound(A, A+n, k)-A); }
int query3(long long i, long long j) { return upper_bound(A, A+n, j)-lower_bound(A, A+n, i); }

int main(void) {
	int m, num;
	long long i, j, k;
	scanf("%d%d", &n, &m);
	for(int i=0 ; i<n ; i++)
		scanf("%lld", &A[i]);
	sort(A, A+n);
	while(m--) {
		scanf("%d", &num);
		if(num==1) {
			scanf("%lld", &k);
			printf("%d\n", query1(k));
		} else if(num==2) {
			scanf("%lld", &k);
			printf("%d\n", query2(k));
		} else if(num==3) {
			scanf("%lld%lld", &i, &j);
			printf("%d\n", query3(i, j));
		}
	}
	return 0;
}