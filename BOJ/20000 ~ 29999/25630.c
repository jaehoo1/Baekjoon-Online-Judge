# include <stdio.h>

int main(void) {
	int N, i, cou=0;
	char str[101];
	scanf("%d%s", &N, str);
	for(i=0 ; i<N/2 ; i++)
		if(str[i]!=str[N-i-1])
			cou++;
	printf("%d", cou);
	return 0;
}