# include <stdio.h>
# include <string.h>

int main(void) {
	int N, hard, min=5;
	char str[11], res[11];
	scanf("%d", &N);
	while(N--) {
		scanf("%s%d", str, &hard);
		if(hard<min) {
			min=hard;
			strcpy(res, str);
		}
	}
	puts(res);
	return 0;
}
