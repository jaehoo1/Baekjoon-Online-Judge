# include <stdio.h>

int main(void) {
	int N, res=0;
	scanf("%d", &N);
	if(N==100000000) {
		res+=9;
		N--;
	}
	if(N>=10000000) {
		res+=8*(N-9999999);
		N=9999999;
	}
	if(N>=1000000) {
		res+=7*(N-999999);
		N=999999;
	}
	if(N>=100000) {
		res+=6*(N-99999);
		N=99999;
	}
	if(N>=10000) {
		res+=5*(N-9999);
		N=9999;
	}
	if(N>=1000) {
		res+=4*(N-999);
		N=999;
	}
	if(N>=100) {
		res+=3*(N-99);
		N=99;
	}
	if(N>=10) {
		res+=2*(N-9);
		N=9;
	}
	res+=N;
	printf("%d", res);
	return 0;
}
