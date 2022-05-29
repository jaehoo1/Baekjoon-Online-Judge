# include <stdio.h>
# include <math.h>

int main(void) {
	char str[6];
	int sum=0, i;
	scanf("%s", str);
	for(i=0 ; i<5 ; i++)
		sum+=pow(str[i]-'0', 5);
	printf("%d", sum);
	return 0;
}
