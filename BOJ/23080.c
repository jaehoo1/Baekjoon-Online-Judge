# include <stdio.h>

int main(void) {
	int K, i;
	char S[1011]={0, };
	scanf("%d%s", &K, S);
	for(i=0 ; S[i] ; i+=K)
		printf("%c", S[i]);
	return 0;
}
