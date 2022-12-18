# include <stdio.h>
# include <string.h>

int main(void) {
	int N, bigdata=0, security=0;
	char str[800001], *ptr;
	scanf("%d%s", &N, str);
	for(ptr=str ; ptr=strstr(ptr, "bigdata") ; ptr++)
		bigdata++;
	for(ptr=str ; ptr=strstr(ptr, "security") ; ptr++)
		security++;
	if(bigdata>security)
		puts("bigdata?");
	else if(bigdata<security)
		puts("security!");
	else
		puts("bigdata? security!");
	return 0;
}