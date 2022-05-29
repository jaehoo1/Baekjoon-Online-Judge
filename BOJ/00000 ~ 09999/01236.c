# include <stdio.h>

int main(void) {
	char str[50][51];
	int N, M, R=0, C=0, i, j, bol;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		scanf("%s", str[i]);
	for(i=0 ; i<N ; i++) {
		bol=0;
		for(j=0 ; j<M ; j++)
			if(str[i][j]=='X') {
				bol=1;
				break;
			}
		if(!bol)R++;
	}
	for(i=0 ; i<M ; i++) {
		bol=0;
		for(j=0 ; j<N ; j++)
			if(str[j][i]=='X') {
				bol=1;
				break;
			}
		if(!bol)C++;
	}
	printf("%d", R>C?R:C);
	return 0;
}
