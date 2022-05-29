# include <stdio.h>

int main(void) {
	char str[251], pre;
	int i;
	scanf("%s", str);
	pre=str[0];
	printf("%c", pre);
	for(i=1 ; str[i] ; i++) {
		if(str[i]!=pre)
			printf("%c", str[i]);
		pre=str[i];
	}
	return 0;
}
