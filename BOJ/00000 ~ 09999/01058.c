# include <stdio.h>
# define	INF	1e9

int main(void) {
	int N, i, j, k, G[50][50], cou, max=0;
	char str[51];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%s", str);
		for(j=0 ; j<N ; j++)
			G[i][j]=str[j]=='Y'?1:INF;
	}
	for(k=0 ; k<N ; k++)
		for(i=0 ; i<N ; i++)
			for(j=0 ; j<N ; j++)
				if(i!=j&&G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
	for(i=0 ; i<N ; i++) {
		cou=0;
		for(j=0 ; j<N ; j++)
			if(G[i][j]<=2)
				cou++;
		if(cou>max)
			max=cou;
	}
	printf("%d", max);
	return 0;
}