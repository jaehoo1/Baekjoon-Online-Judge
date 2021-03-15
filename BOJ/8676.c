# include <stdio.h>

int main(void) {
	int n, i, j, temp[3], arr[1000000];
	scanf("%d", &n);
	for(i=0 ; i<n ; i++)
		scanf("%d", &arr[i]);
	for(i=0 ; i<n-2 ; i++) {
		for(j=0 ; j<3 ; j++)
			temp[j]=0;
		for(j=0 ; j<3 ; j++)
			temp[arr[i+j]]=1;
		if(temp[0]&&temp[1]&&temp[2]) {
			puts("TAK");
			return 0;
		}
	}
	puts("NIE");
	return 0;
}
