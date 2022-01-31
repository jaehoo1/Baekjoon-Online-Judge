# include <stdio.h>

int main(void) {
	int n, num, mul=0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &num);
		if(!mul)
			mul=num;
		else if(num%mul==0) {
			printf("%d\n", num);
			mul=0;
		}
	}
	return 0;
}
