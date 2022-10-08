# include <stdio.h>

char keyboard[4][14]={"`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};

char left(char c) {
	int i, j;
	if(c==' ')
		return c;
	for(i=0 ; i<4 ; i++)
		for(j=0 ; keyboard[i][j] ; j++)
			if(keyboard[i][j]==c)
				return keyboard[i][j-1];
}

int main(void) {
	int i;
	char str[100001];
	while(gets(str)) {
		for(i=0 ; str[i] ; i++)
			str[i]=left(str[i]);
		puts(str);
	}
	return 0;
}