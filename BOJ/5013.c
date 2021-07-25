# include <stdio.h>
# include <string.h>

int main(void) {
	int n, cou=0;
	char ki[1001];
	scanf("%d", &n);
	while(n--) {
		scanf("%s", ki);
		if(!strstr(ki, "CD"))
			cou++;
	}
	printf("%d", cou);
	return 0;
}
