# include <stdio.h>

int main(void) {
	int n, num, zero=0, one=0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &num);
		if(num)one++;
		else	zero++;
	}
	printf("%d", one>zero?zero:one);
	return 0;
}
