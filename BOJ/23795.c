# include <stdio.h>

int main(void) {
	int num, sum=0;
	while(scanf("%d", &num)) {
		if(num==-1)
			break;
		sum+=num;
	}
	printf("%d", sum);
	return 0;
}
