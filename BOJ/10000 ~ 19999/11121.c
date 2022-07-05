# include <stdio.h>
# include <string.h>

int main(void) {
	int T;
	char str1[121], str2[121];
	scanf("%d", &T);
	while(T--) {
		scanf("%s%s", str1, str2);
		puts(strcmp(str1, str2)?"ERROR":"OK");
	}
	return 0;
}