# include <stdio.h>

int main(void) {
	int A, B, cou;
	while(scanf("%d%d", &A, &B)) {
		if(!A&&!B)return 0;
		A-=B;
		cou=0;
		while(A>3) {
			cou++;
			A-=2;
		}
		if(A==3)printf("%d 1\n", cou);
		else if(A==2)printf("%d 0\n", cou+1);
		else	printf("%d 0\n", cou);
	}
	return 0;
}
