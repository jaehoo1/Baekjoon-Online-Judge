# include <stdio.h>

int main(void) {
	char str[20][21]={0, };
	int N, i, j;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		str[0][i]='*';
		str[i][0]='*';
		str[N-1][i]='*';
		str[i][N-1]='*';
		str[i][i]='*';
		str[i][N-1-i]='*';
	}
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<N ; j++)
			printf("%c", str[i][j]?'*':' ');
		puts("");
	}
	return 0;
}
