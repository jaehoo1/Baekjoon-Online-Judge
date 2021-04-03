# include <stdio.h>

long long power(const long long x) {
	return x*x;
}

int main(void) {
	int n, i, arr[1000000];
	long long res=0;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
		scanf("%d", &arr[i]);
	for(i=0 ; i<n-1 ; i++)
		res+=power(arr[i+1]-arr[i]);
	printf("%lld", res);
	return 0;
}
