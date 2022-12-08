# include <stdio.h>

int main(void) {
	int n, v, arr[1000], i, cou;
	while(scanf("%d", &n)) {
		if(!n)
			break;
		cou=0;
		for(i=0 ; i<n ; i++)
			scanf("%d", &arr[i]);
		for(i=1 ; i<n-1 ; i++)
			if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
				cou++;
		printf("%d\n", cou);
	}
	return 0;
}