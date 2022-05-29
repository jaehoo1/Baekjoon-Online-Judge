# include <stdio.h>

int flag(int arr[6]) {
	int i;
	for(i=0 ; i<6 ; i++)
		if(arr[i])
			return 0;
	return 1;
}

int main(void) {
	int arr[6], i, max, min;
	double sum;
	while(1) {
		sum=0;	max=0;	min=10;
		for(i=0 ; i<6 ; i++) {
			scanf("%d", &arr[i]);
			if(arr[i]>max)max=arr[i];
			if(arr[i]<min)min=arr[i];
		}
		for(i=0 ; !arr[i] ; i++);
		if(flag(arr))break;
		for(i=0 ; i<6 ; i++)
			sum+=arr[i];
		sum-=max;
		sum-=min;
		printf("%g\n", sum/4);
	}
	return 0;
}
