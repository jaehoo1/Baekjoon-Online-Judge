# include <stdio.h>

int main(void) {
	int N, M, sum[1025][1025]={0, }, num, i, j, x1, y1, x2, y2;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		for(j=1 ; j<=N ; j++) {
			scanf("%d", &num);
			sum[i][j]=sum[i][j-1]+num;
		}
	while(M--) {
		num=0;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for(i=x1 ; i<=x2 ; i++) {
			num+=sum[i][y2];
			num-=sum[i][y1-1];
		}
		printf("%d\n", num);
	}
	return 0;
}
