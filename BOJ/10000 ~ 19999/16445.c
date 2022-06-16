# include <stdio.h>

int main(void) {
	int N, num, cou=0;
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &num);
		if(num==2||num==3)
			cou++;
	}
	printf("%d", cou);
	return 0;
}