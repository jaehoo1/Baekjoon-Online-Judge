# include <stdio.h>

int main(void) {
	int N, i, s=0, t=0;
	char str[101];
	scanf("%d%s", &N, str);
	for(i=0 ; i<N ; i++)
		if(str[i]=='s')
			s++;
		else if(str[i]=='t')
			t++;
	for(i=0 ; i<N&&s!=t ; i++)
		if(str[i]=='s')
			s--;
		else
			t--;
	printf("%s", &str[i]);
	return 0;
}