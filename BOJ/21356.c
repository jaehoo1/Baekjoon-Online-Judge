# include <stdio.h>

int main(void) {
	int N, cou=0;
	scanf("%d", &N);
	while(N>0) {
		if(N>=111111111)N-=111111111;
		else if(N>=11111111)N-=11111111;
		else if(N>=1111111)N-=1111111;
		else if(N>=111111)N-=111111;
		else if(N>=11111)N-=11111;
		else if(N>=1111)N-=1111;
		else if(N>=111)N-=111;
		else if(N>=11)N-=11;
		else	N--;
		cou++;
	}
	printf("%d", cou);
	return 0;
}
