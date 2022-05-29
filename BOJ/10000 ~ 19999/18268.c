# include <stdio.h>

int idx(const int *arr, const int key, const int len) {
	int i;
	for(i=0 ; i<len ; i++)
		if(arr[i]==key)
			return i;
}

int main(void) {
	int K, N, i, j, a, b, arr[10][20], cou=0, temp;
	scanf("%d%d", &K, &N);
	for(i=0 ; i<K ; i++)
		for(j=0 ; j<N ; j++)
			scanf("%d", &arr[i][j]);
	for(a=1 ; a<=N-1 ; a++)
		for(b=a+1 ; b<=N ; b++) {
			if(idx(arr[0], a, N)<idx(arr[0], b, N))
				temp=0;
			else
				temp=1;
			for(i=1 ; i<K ; i++)
				if(idx(arr[i], a, N)<idx(arr[i], b, N)) {
					if(temp) {
						temp=-1;
						break;
					}
				}
				else
					if(!temp) {
						temp=-1;
						break;
					}
			if(temp!=-1)
				cou++;
		}
	printf("%d", cou);
	return 0;
}
