# include <stdio.h>

char map[64][65];

void recur(const int x, const int y, int N) {
	int i, j, flag=0;
	char first=map[x][y];
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
			if(first!=map[i+x][j+y]) {
				flag=1;
				break;
			}
	if(!flag)
		printf("%c", first);
	else {
		printf("(");
		N/=2;
		recur(x, y, N);
		recur(x, y+N, N);
		recur(x+N, y, N);
		recur(x+N, y+N, N);
		printf(")");
	}
}

int main(void) {
	int N, i;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%s", map[i]);
	recur(0, 0, N);
	return 0;
}
