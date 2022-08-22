# include <stdio.h>

int is_repeat_number(int num) {
	char str[5];
	int i, digit[10]={0, };
	sprintf(str, "%d", num);
	for(i=0 ; str[i] ; i++)
		digit[str[i]-'0']++;
	for(i=0 ; i<10 ; i++)
		if(digit[i]>=2)
			return 1;
	return 0;
}

int main(void) {
	int N, M, cou;
	while(~scanf("%d%d", &N, &M)) {
		cou=0;
		for( ; N<=M ; N++)
			if(!is_repeat_number(N))
				cou++;
		printf("%d\n", cou);
	}
	return 0;
}