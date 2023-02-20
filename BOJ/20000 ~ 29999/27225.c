# include <stdio.h>
# define	min(a, b)	(a<b?a:b)

int main(void) {
	int n, m, res=0;
	scanf("%d%d", &n, &m);
	if((n+m)%2) {
		if(n>m)
			n--;
		else
			m--;
		res++;
	}
	res+=2*min(n, m);
	printf("%d", res);
	return 0;
}