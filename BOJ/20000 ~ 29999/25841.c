# include <stdio.h>

int main(void) {
	int a, b, digit, i, cou=0;
	char str[5];
	scanf("%d%d%d", &a, &b, &digit);
	while(a<=b) {
		sprintf(str, "%d", a++);
		for(i=0 ; i<4 ; i++)
			if(str[i]-'0'==digit)
				cou++;
	}
	printf("%d", cou);
	return 0;
}