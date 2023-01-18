# include <stdio.h>

char replace(char c) {
	switch(c) {
	case 'y':
		return 'a';
	case 'a':
		return 'e';
	case 'e':
		return 'i';
	case 'i':
		return 'o';
	case 'o':
		return 'u';
	case 'u':
		return 'y';
	case 'Y':
		return 'A';
	case 'A':
		return 'E';
	case 'E':
		return 'I';
	case 'I':
		return 'O';
	case 'O':
		return 'U';
	case 'U':
		return 'Y';
	default:
		return c;
	}
}
void replacestr(char *str) {
	int i;
	for(i=0 ; str[i] ; i++)
		str[i]=replace(str[i]);
}

int main(void) {
	int n;
	char str[100001];
	scanf("%d", &n);
	getchar();
	while(n--) {
		gets(str);
		replacestr(str);
		puts(str);
	}
	return 0;
}