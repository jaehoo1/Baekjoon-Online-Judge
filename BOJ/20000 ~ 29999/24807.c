# include <stdio.h>

int main(void) {
	int b, d, c, l, sum, i, j, k, flag=0;
	scanf("%d%d%d%d", &b, &d, &c, &l);
	for(i=0 ; ; i++) {
		sum=b*i;
		if(sum>l)
			break;
		for(j=0 ; ; j++) {
			sum=b*i+d*j;
			if(sum>l)
				break;
			for(k=0 ; ; k++) {
				sum=b*i+d*j+c*k;
				if(sum==l) {
					flag=1;
					printf("%d %d %d\n", i, j, k);
				}
				if(sum>l)
					break;
			}
		}
	}
	if(!flag)
		puts("impossible");
	return 0;
}