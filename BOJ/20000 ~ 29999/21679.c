# include <stdio.h>

int main(void) {
	int n, c[101], k, p, i;
	scanf("%d", &n);
	for(i=1 ; i<=n ; i++)
		scanf("%d", &c[i]);
	scanf("%d", &k);
	while(k--) {
		scanf("%d", &p);
		c[p]--;
	}
	for(i=1 ; i<=n ; i++)
		puts(c[i]>=0?"no":"yes");
	return 0;
}