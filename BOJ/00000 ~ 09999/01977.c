# include <stdio.h>
# include <math.h>

int is_square_number(int num) { return pow((int)sqrt(num), 2)==num; }

int main(void) {
	int M, N, min=-1, sum=0;
	scanf("%d%d", &M, &N);
	for( ; M<=N ; M++)
		if(is_square_number(M)) {
			if(min==-1)
				min=M;
			sum+=M;
		}
	if(min==-1)
		puts("-1");
	else
		printf("%d\n%d", sum, min);
	return 0;
}