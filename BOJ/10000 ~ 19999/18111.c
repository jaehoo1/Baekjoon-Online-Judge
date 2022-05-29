# include <stdio.h>

int main(void) {
	int N, M, B, h, i, j, block, min_time=2147483647, height, arr[500][500], time, flag;
	scanf("%d%d%d", &N, &M, &B);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			scanf("%d", &arr[i][j]);
	for(h=0 ; h<=256 ; h++) {
		time=0;
		flag=1;
		block=B;
		for(i=0 ; i<N ; i++)
			for(j=0 ; j<M ; j++)
				if(arr[i][j]<h) {
					time+=h-arr[i][j];
					block-=h-arr[i][j];
				} else if(arr[i][j]>h) {
					time+=2*(arr[i][j]-h);
					block+=arr[i][j]-h;
				} else
					continue;
		if(block<0)
			continue;
		if(time<=min_time) {
			min_time=time;
			height=h;
		}
	}
	printf("%d %d", min_time, height);
	return 0;
}
