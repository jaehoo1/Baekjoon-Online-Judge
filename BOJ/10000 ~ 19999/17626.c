# include <stdio.h>

int main(void) {
	int n, a, b, c, sum;
	scanf("%d", &n);
	for(a=1 ; a*a<n ; a++);
	if(a*a==n) {
		puts("1");
		return 0;
	}
	for(a=1 ; a*a<n ; a++) {
		sum=a*a;
		for(b=1 ; ; b++) {
			sum=a*a+b*b;
			if(sum==n) {
				puts("2");
				return 0;
			} else if(sum>n)
				break;
		}
	}
	for(a=1 ; a*a<n ; a++) {
		sum=a*a;
		for(b=1 ; ; b++) {
			sum=a*a+b*b;
			if(sum>=n)
				break;
			for(c=1 ; ; c++) {
				sum=a*a+b*b+c*c;
				if(sum==n) {
					puts("3");
					return 0;
				} else if(sum>n)
					break;
			}
		}
	}
	puts("4");
	return 0;
}
