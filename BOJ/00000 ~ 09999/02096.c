# include <stdio.h>

int max(int a, int b) { return a>b?a:b; }
int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int N, arr[3], i, j, maxarr[2][3], minarr[2][3];
	scanf("%d", &N);
	for(i=0 ; i<3 ; i++) {
		scanf("%d", &arr[i]);
		maxarr[1][i]=minarr[1][i]=arr[i];
	}
	for(i=1 ; i<N ; i++) {
		for(j=0 ; j<3 ; j++) {
			maxarr[0][j]=maxarr[1][j];
			minarr[0][j]=minarr[1][j];
			scanf("%d", &arr[j]);
		}
		maxarr[1][0]=arr[0]+max(maxarr[0][0], maxarr[0][1]);
		maxarr[1][1]=arr[1]+max(maxarr[0][0], max(maxarr[0][1], maxarr[0][2]));
		maxarr[1][2]=arr[2]+max(maxarr[0][1], maxarr[0][2]);
		minarr[1][0]=arr[0]+min(minarr[0][0], minarr[0][1]);
		minarr[1][1]=arr[1]+min(minarr[0][0], min(minarr[0][1], minarr[0][2]));
		minarr[1][2]=arr[2]+min(minarr[0][1], minarr[0][2]);
	}
	printf("%d %d", max(maxarr[1][0], max(maxarr[1][1], maxarr[1][2])), min(minarr[1][0], min(minarr[1][1], minarr[1][2])));
	return 0;
}