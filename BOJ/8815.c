# include <stdio.h>

int main(void) {
	char str[13]="ABCBCDCDADAB";
	int Z, N;
	scanf("%d", &Z);
	while(Z--) {
		scanf("%d", &N);
		printf("%c\n", str[(N-1)%12]);
	}
	return 0;
}
