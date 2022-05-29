# include <stdio.h>

int main(void) {
	int n, num, i;
	char str[7];
	scanf("%d", &n);
	for(i=1 ; i<=n ; i++) {
		scanf("%s", str);
		if(str[0]>='0'&&str[0]<='9') {
			sscanf(str, "%d", &num);
			if(num!=i) {
				puts("something is fishy");
				return 0;
			}
		}
	}
	puts("makes sense");
	return 0;
}
