# include <stdio.h>

int main(void) {
	int n, num, sum=0, min=0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &num);
		sum+=num;
		if(sum<0&&sum<min)
			min=sum;
	}
	printf("%d", -min);
	return 0;
}
