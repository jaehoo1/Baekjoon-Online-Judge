# include <stdio.h>

int main(void) {
	int N, i, num, max=0, idx, arr[10001]={0, };
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &num);
		arr[num]++;
	}
	for(i=1 ; i<=10000 ; i++)
		if(arr[i]>max) {
			max=arr[i];
			idx=i;
		}
	printf("%d", idx);
	return 0;
}
