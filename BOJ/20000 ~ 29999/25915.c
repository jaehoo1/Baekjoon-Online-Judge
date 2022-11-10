# include <stdio.h>
# include <math.h>

int dist(char a, char b) {
	return abs(a-b);
}

int main(void) {
	char str[13]=" ILOVEYONSEI";
	int res=0, i;
	scanf("%c", &str[0]);
	for(i=0 ; str[i+1] ; i++)
		res+=dist(str[i], str[i+1]);
	printf("%d", res);
	return 0;
}