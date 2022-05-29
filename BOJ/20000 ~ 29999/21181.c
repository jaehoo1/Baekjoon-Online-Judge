# include <stdio.h>

int main(void) {
	int n, i, j, min=2147483647, arr[50], sum, k;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
		scanf("%d", &arr[i]);
	for(i=0 ; i<n-1 ; i++)
		for(j=i+1 ; j<n ; j++) {
			sum=0;
			for(k=0 ; k<n ; k++)
				sum+=(arr[k]-arr[i])*(arr[k]-arr[i])<(arr[k]-arr[j])*(arr[k]-arr[j])?(arr[k]-arr[i])*(arr[k]-arr[i]):(arr[k]-arr[j])*(arr[k]-arr[j]);
			if(sum<min)
				min=sum;
		}
	printf("%d", min);
	return 0;
}
