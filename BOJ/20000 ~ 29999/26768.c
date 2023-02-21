# include <stdio.h>

int main(void) {
	char c;
	while(~scanf("%c", &c))
		if(c=='a')
			printf("4");
		else if(c=='e')
			printf("3");
		else if(c=='i')
			printf("1");
		else if(c=='o')
			printf("0");
		else if(c=='s')
			printf("5");
		else
			printf("%c", c);
	return 0;		
}