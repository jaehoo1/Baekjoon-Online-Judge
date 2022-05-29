# include <stdio.h>

int main(void) {
	char N[8];
	int arr[9]={0, }, i, max=0;
	scanf("%s", N);
	for(i=0 ; N[i] ; i++)
		if(N[i]=='6'||N[i]=='9')
			arr[6]++;
		else
			arr[N[i]-'0']++;
	arr[6]=(arr[6]+1)/2;
	for(i=0 ; i<9 ; i++)
		if(arr[i]>max)
			max=arr[i];
	printf("%d", max);
	return 0;
}
