# include <stdio.h>

int count_zero(int num) {
	char str[8];
	int i, zero=0;
	sprintf(str, "%d", num);
	for(i=0 ; str[i] ; i++)
		if(str[i]=='0')
			zero++;
	return zero;
}

int main(void) {
	int T, N, M, cou;
	scanf("%d", &T);
	while(T--) {
		cou=0;
		scanf("%d%d", &N, &M);
		while(N<=M)
			cou+=count_zero(N++);
		printf("%d\n", cou);
	}
	return 0;
}