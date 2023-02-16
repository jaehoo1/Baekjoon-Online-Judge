# include <stdio.h>

int main(void) {
	int n, r, salary, fxd=0, dble=0, i;
	scanf("%d%d", &n, &r);
	while(n--) {
		scanf("%d", &salary);
		if(salary>r)
			dble++;
		else if(salary<r)
			fxd++;
	}
	if(fxd>dble)
		puts("1");
	else if(fxd<dble)
		puts("2");
	else
		puts("0");
	return 0;
}