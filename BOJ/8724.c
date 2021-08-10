# include <stdio.h>

int main(void) {
	int N, max=0, num, temp=0;
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &num);
		if(num)temp++;
		else {
			if(temp>max)
				max=temp;
			temp=0;
		}
	}
	if(temp>max)max=temp;
	printf("%d", max);
	return 0;
}
