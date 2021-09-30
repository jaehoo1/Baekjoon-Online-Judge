# include <stdio.h>
# include <string.h>

int main(void) {
	int N, num, max=0;
	char str[100], win[100];
	scanf("%d", &N);
	while(N--) {
		scanf("%s%d", str, &num);
		if(num>max) {
			max=num;
			strcpy(win, str);
		}
	}
	puts(win);
	return 0;
}
