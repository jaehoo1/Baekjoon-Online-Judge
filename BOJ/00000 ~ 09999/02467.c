# include <stdio.h>
# include <math.h>

int main(void) {
	int N, i, arr[100000], start=0, end, res1, res2, abs_min=2000000001;
	scanf("%d", &N);
	end=N-1;
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	while(start!=end) {
		if(abs(arr[start]+arr[end])<abs_min){
			abs_min=abs(arr[start]+arr[end]);
			res1=arr[start];
			res2=arr[end];
		}
		if(arr[start]+arr[end]<0)
			start++;
		else if(arr[start]+arr[end]>0)
			end--;
		else
			break;
	}
	printf("%d %d", res1, res2);
	return 0;
}
