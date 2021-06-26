# include <stdio.h>
# include <string.h>

int main(void) {
	char N[20];
	int i, len;
	scanf("%s", N);
	len=strlen(N);
	for(i=0 ; i<len/2 ; i++)
		printf("%c", N[i]);
	printf(" ");
	puts(&N[len/2]);
	return 0;
}
