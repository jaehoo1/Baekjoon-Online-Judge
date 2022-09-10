# include <stdio.h>
# include <string.h>

int main(void) {
	int N;
	char str[21];
	scanf("%d", &N);
	while(N--) {
		scanf("%s", str);
		if(strlen(str)>=6&&strlen(str)<=9)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}