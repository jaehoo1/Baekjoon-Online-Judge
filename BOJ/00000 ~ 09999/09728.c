# include <stdio.h>

int main(void) {
	int T, t, N, M, arr[20000], i, j, cou;
	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		scanf("%d%d", &N, &M);
		cou=0;
		for(i=0 ; i<N ; i++)
			scanf("%d", &arr[i]);
		i=0;
		j=N-1;
		while(i<j)
			if(arr[i]+arr[j]<M)
				i++;
			else if(arr[i]+arr[j]==M) {
				i++;
				j--;
				cou++;
			} else if(arr[i]+arr[j]>M)
				j--;
		printf("Case #%d: %d\n", t, cou);
	}
	return 0;
}