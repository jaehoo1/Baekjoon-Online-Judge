# include <stdio.h>

int main(void) {
	int arr[1001][1001]={0, }, N, i, j, k, a, b, c, d, cou[101]={0, };
	scanf("%d", &N);
	for(i=1 ; i<=N ; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		c=a+c-1;
		d=b+d-1;
		for(j=a ; j<=c ; j++)
			for(k=b ; k<=d ; k++)
				arr[j][k]=i;
	}
	for(i=0 ; i<=1000 ; i++)
		for(j=0 ; j<=1000 ; j++)
			cou[arr[i][j]]++;
	for(i=1 ; i<=N ; i++)
		printf("%d\n", cou[i]);
	return 0;
}