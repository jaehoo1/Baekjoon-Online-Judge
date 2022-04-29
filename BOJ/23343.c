# include <stdio.h>

int isnumber(char str[]) {
	int i;
	for(i=0 ; str[i] ; i++)
		if(str[i]<'0'||str[i]>'9')
			return 0;
	return 1;
}

int main(void) {
	char x[6], y[6];
	int X, Y;
	scanf("%s%s", x, y);
	if(!isnumber(x)||!isnumber(y)) {
		puts("NaN");
		return 0;
	}
	sscanf(x, "%d", &X);
	sscanf(y, "%d", &Y);
	printf("%d", X-Y);
	return 0;
}
