# include <stdio.h>

int main(void) {
	int B=0, C=0, i;
	char str[1000001];
	scanf("%s", str);
	for(i=0 ; str[i] ; i++)
		if(str[i]=='B')
			B++;
		else if(str[i]=='C')
			C++;
	printf("%d", B/2+C/2);
	return 0;
}