# include <stdio.h>

int main(void) {
	int S1, S2, S3, arr[81]={0, }, i, j, k, max=0;
	scanf("%d%d%d", &S1, &S2, &S3);
	for(i=1 ; i<=S1 ; i++)
		for(j=1 ; j<=S2 ; j++)
			for(k=1 ; k<=S3 ; k++)
				arr[i+j+k]++;
	for(i=0 ; i<=80 ; i++)
		if(arr[i]>max)
			max=arr[i];
	for(i=0 ; i<=80 ; i++)
		if(arr[i]==max) {
			printf("%d", i);
			return 0;
		}
	return 0;
}