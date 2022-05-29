# include <stdio.h>

int main(void) {
	int len;
	char S[100001];
	scanf("%d%s", &len, S);
	printf("%s", &S[len-5]);
	return 0;
}
