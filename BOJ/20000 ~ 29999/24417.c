# include <stdio.h>

int main(void) {
	int n, i;
	long long pre1=0, pre2=1, cur;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++) {
		cur=(pre1+pre2)%1000000007;
		pre2=pre1;
		pre1=cur;
	}
	printf("%lld %d", cur, n-2);
	return 0;
}