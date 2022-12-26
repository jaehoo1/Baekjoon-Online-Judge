# include <stdio.h>

int main(void) {
	int H, M, S;
	scanf("%d%d%d", &H, &M, &S);
	S++;
	if(S==60) {
		S=0;
		M++;
	}
	if(M==60) {
		M=0;
		H++;
	}
	if(H==24)
		H=0;
	printf("%02d:%02d:%02d", H, M, S);
	return 0;
}