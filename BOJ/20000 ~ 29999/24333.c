# include <stdio.h>

int main(void) {
	int l1, r1, l2, r2, k, cou=0;
	scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &k);
	for( ; l1<=r1 ; l1++)
		if(l1>=l2&&l1<=r2&&l1!=k)
			cou++;
	printf("%d", cou);
	return 0;
}