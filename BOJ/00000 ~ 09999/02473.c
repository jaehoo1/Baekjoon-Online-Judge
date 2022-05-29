# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) {
	if(*a<*b)return -1;
	else if(*a>*b)return 1;
	else	return 0;
}
long long Abs(long long n) {
	if(n>0)return n;
	return -n;
}

int main(void) {
	int N, arr[5000], i, j, k, res1, res2, res3;
	long long abs_min=3000000000, sum;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	for(i=0 ; i<N-2 ; i++) {
		j=i+1;
		k=N-1;
		while(j!=k) {
			sum=(long long)arr[i]+(long long)arr[j]+(long long)arr[k];
			if(Abs(sum)<abs_min){
				abs_min=Abs(sum);
				res1=arr[i];	res2=arr[j];	res3=arr[k];
			}
			if(sum<0)
				j++;
			else if(sum>0)
				k--;
			else
				break;
		}
	}
	printf("%d %d %d", res1, res2, res3);
	return 0;
}
