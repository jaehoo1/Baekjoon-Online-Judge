# include <stdio.h>

int main(void) {
	int arr[3], max=0, i, sum=0;
	for(i=0 ; i<3 ; i++) {
		scanf("%d", &arr[i]);
		if(arr[i]>max)
			max=arr[i];
	}
	for(i=0 ; i<3 ; i++)
		sum+=max-arr[i];
	printf("%d", sum);
	return 0;
}
