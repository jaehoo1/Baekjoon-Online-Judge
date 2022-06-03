# include <stdio.h>

int main(void) {
	int H, W, N, M, R, C;
	scanf("%d%d%d%d", &H, &W, &N, &M);
	R=H/(N+1);
	if(H%(N+1))
		R++;
	C=W/(M+1);
	if(W%(M+1))
		C++;
	printf("%d", R*C);
	return 0;
}