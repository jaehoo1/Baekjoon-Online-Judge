# include <stdio.h>
# include <string.h>

int main(void) {
	int N, cou=0;
	char str[21];
	scanf("%d", &N);
	while(N--) {
		scanf("%s", str);
		if(!strcmp(str, "he")||!strcmp(str, "him")||!strcmp(str, "she")||!strcmp(str, "her"))
			cou++;
	}
	printf("%d", cou);
	return 0;
}