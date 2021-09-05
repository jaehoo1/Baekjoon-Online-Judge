# include <stdio.h>

int main(void) {
	int N, M, num, arr[1001]={0, }, i, max=0;
	scanf("%d%d", &N, &M);
	while(N--) {
		scanf("%d", &num);
		arr[num]++;
	}
	for(i=1 ; i<=M ; i++)
		if(arr[i]>max)
			max=arr[i];
	printf("%d", max);
	return 0;
}
