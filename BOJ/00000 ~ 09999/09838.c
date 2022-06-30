# include <stdio.h>

int main(void) {
	int n, k, i, arr[20001];
	scanf("%d", &n);
	for(i=1 ; i<=n ; i++) {
		scanf("%d", &k);
		arr[k]=i;
	}
	for(i=1 ; i<=n ; i++)
		printf("%d\n", arr[i]);
	return 0;
}