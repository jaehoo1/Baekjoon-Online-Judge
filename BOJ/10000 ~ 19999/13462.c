# include <stdio.h>
# include <string.h>

int main(void) {
	char str[1000003];
	int i, len, R, B, L;
	scanf("%s", str);
	len=strlen(str);
	for(i=0 ; i<len ; i++) {
		R=0;
		B=0;
		L=0;
		if(str[i]=='R')R=1;
		else if(str[i]=='B')B=1;
		else if(str[i]=='L')L=1;
		if(str[i+1]=='R')R=1;
		else if(str[i+1]=='B')B=1;
		else if(str[i+1]=='L')L=1;
		if(str[i+2]=='R')R=1;
		else if(str[i+2]=='B')B=1;
		else if(str[i+2]=='L')L=1;
		if(R&&B&&L) {
			printf("C");
			i+=2;
			continue;
		}
		if(str[i]=='R')printf("S");
		else if(str[i]=='B')printf("K");
		else if(str[i]=='L')printf("H");
	}
	return 0;
}
