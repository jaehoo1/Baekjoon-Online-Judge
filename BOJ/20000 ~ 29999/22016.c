# include <stdio.h>

int main(void) {
	char T[101];
	int N, K, i;
	scanf("%d%d%s", &N, &K, T);
	K--;
	for(i=0 ; i<K ; i++)
		printf("%c", T[i]);
	for( ; i<N ; i++)
		printf("%c", T[i]<='Z'?T[i]+32:T[i]-32);
	return 0;
}
