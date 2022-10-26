# include <stdio.h>

int main(void) {
	int N, n, cou[1001]={0, }, max=0, i;
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &n);
		cou[n]++;
	}
	for(i=1 ; i<=1000 ; i++)
		if(cou[i]>max)
			max=cou[i];
	printf("%d", max);
	return 0;
}