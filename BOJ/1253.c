# include <stdio.h>
# include <stdlib.h>

int intcmp(const int *a, const int *b) {
	if(*a<*b)return -1;
	else if(*a>*b)return 1;
	else	return 0;
}

int main(void) {
	int N, i, arr[2000], start, end, cou=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, 4, (int(*)(const void*, const void*))intcmp);
	for(i=0 ; i<N ; i++) {
		start=0;
		end=N-1;
		while(start<end) {
			if(start==i) {
				start++;
				continue;
			}
			if(end==i) {
				end--;
				continue;
			}
			if(arr[start]+arr[end]<arr[i])
				start++;
			else if(arr[start]+arr[end]>arr[i])
				end--;
			else {
				cou++;
				break;
			}
		}
	}
	printf("%d", cou);
	return 0;
}
