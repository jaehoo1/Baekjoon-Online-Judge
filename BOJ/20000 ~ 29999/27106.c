# include <stdio.h>

int main(void) {
	int P, cent[4]={25, 10, 5, 1}, i;
	scanf("%d", &P);
	P=100-P;
	for(i=0 ; i<4 ; i++) {
		printf("%d ", P/cent[i]);
		P%=cent[i];
	}
	return 0;
}