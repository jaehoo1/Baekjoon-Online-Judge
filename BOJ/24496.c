# include <stdio.h>
# include <math.h>

int main(void) {
	int T, N, arr[100000], i, min;
	long long res, temp;
	scanf("%d", &T);
	while(T--) {
		res=0;
		min=1000000001;
		scanf("%d", &N);
		for(i=0 ; i<N ; i++)
			scanf("%d", &arr[i]);
		for(i=0 ; i<N ; i++) {
			if(i<N-2&&arr[i]<arr[i+1]) {
				temp=arr[i+1]-arr[i];
				arr[i+1]-=temp;
				arr[i+2]-=temp;
				res+=temp*2;
			}
			if(arr[i]<min)
				min=arr[i];
		}
		for(i=0 ; i<N ; i++) {
			if(arr[i]!=min&&i<N-1&&arr[i]==arr[i+1]) {
				temp=arr[i]-min;
				arr[i]-=temp;
				arr[i+1]-=temp;
				res+=temp*2;
			}
			if(arr[i]!=min||arr[i]<0) {
				res=-1;
				break;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
