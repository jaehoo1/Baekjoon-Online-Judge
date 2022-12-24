# include <stdio.h>

int main(void) {
	int N, lev, max=0, res, i;
	scanf("%d", &N);
	for(i=0, lev=N ; i<8&&lev<210 ; i++, lev++);
	if(lev>=max) {
		max=lev;
		res=1;
	}
	for(i=0, lev=N ; i<4&&lev<220 ; i++, lev++);
	if(lev>=max) {
		max=lev;
		res=2;
	}
	for(i=0, lev=N ; i<2&&lev<230 ; i++, lev++);
	if(lev>=max) {
		max=lev;
		res=3;
	}
	for(i=0, lev=N ; i<1 ; i++, lev++);
	if(lev>=max) {
		max=lev;
		res=4;
	}
	printf("%d", res);
	return 0;
}