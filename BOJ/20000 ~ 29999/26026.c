# include <stdio.h>

int main(void) {
	int n, i, cou=0, coffee=0;
	char str[100001];
	scanf("%d%s", &n, str);
	for(i=0 ; i<n ; i++)
		if(str[i]=='1') {
			cou++;
			coffee=2;
		} else if(str[i]=='0'&&coffee) {
			cou++;
			coffee--;
		}
	printf("%d", cou);
	return 0;
}