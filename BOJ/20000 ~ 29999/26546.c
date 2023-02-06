# include <stdio.h>

int main(void) {
	char str[1001];
	int n, i, j;
	scanf("%d", &n);
	while(n--) {
		scanf("%s%d%d", str, &i, &j);
		str[i]=0;
		printf("%s%s\n", str, &str[j]);
	}
	return 0;
}