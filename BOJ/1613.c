# include <stdio.h>

typedef enum {
	false, true
}bool;

int main(void) {
	int n, k, s, A, B, i, j;
	bool G[401][401]={false, };
	scanf("%d%d", &n, &k);
	while(k--) {
		scanf("%d%d", &A, &B);
		G[A][B]=true;
	}
	for(k=1 ; k<=n ; k++)
		for(i=1 ; i<=n ; i++)
			for(j=1 ; j<=n ; j++)
				if(G[i][k]&&G[k][j])
					G[i][j]=true;
	scanf("%d", &s);
	while(s--) {
		scanf("%d%d", &A, &B);
		if(G[A][B])
			puts("-1");
		else if(G[B][A])
			puts("1");
		else
			puts("0");
	}
	return 0;
}
