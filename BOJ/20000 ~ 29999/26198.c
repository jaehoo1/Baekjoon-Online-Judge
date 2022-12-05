# include <stdio.h>

int main(void) {
	int T, i, year;
	char str[1001];
	scanf("%d", &T);
	getchar();
	while(T--) {
		year=0;
		gets(str);
		for(i=0 ; str[i] ; i++)
			switch(str[i]) {
				case 'I':
					year++;
					break;
				case 'V':
					year+=5;
					break;
				case 'X':
					year+=10;
					break;
				case 'L':
					year+=50;
					break;
				case 'C':
					year+=100;
					break;
				case 'D':
					year+=500;
					break;
				case 'M':
					year+=1000;
					break;
			}
		printf("%d\n", year);
	}
	return 0;
}