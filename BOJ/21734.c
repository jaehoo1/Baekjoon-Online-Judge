# include <stdio.h>

int iter(const char c) {
	if(c<100)
		return c/10+c%10;
	return 1+(c/10)%10+c%10;
}

int main(void) {
	char S[11];
	int i, j;
	scanf("%s", S);
	for(i=0 ; S[i] ; i++) {
		for(j=0 ; j<iter(S[i]) ; j++)
			printf("%c", S[i]);
		puts("");
	}
	return 0;
}
