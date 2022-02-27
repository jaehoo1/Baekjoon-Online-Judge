# include <stdio.h>

int main(void) {
	int N, i, cou=0;
	char str[1000001];
	scanf("%d%s", &N, str);
	for(i=0 ; i<N ; i++)
		if(str[i]=='1')
			cou++;
	printf("%d", cou);
	return 0;
}
