# include <stdio.h>

int main(void) {
	int n, a, i, cou=1;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++) {
		scanf("%d", &a);
		if(a==cou)
			cou++;
	}
	printf("%d", n-cou+1);
	return 0;
}