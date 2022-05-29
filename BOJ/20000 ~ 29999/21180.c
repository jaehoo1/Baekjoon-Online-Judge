# include <stdio.h>

int main(void) {
	int n, i, arr[10000], sum=0;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++) {
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	for(i=0 ; i<n ; i++)
		if(sum-arr[i]==arr[i]) {
			printf("%d", arr[i]);
			return 0;
		}
	puts("BAD");
	return 0;
}
