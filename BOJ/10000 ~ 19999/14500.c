# include <stdio.h>
# define	sum	a+b+c+d
# define	update	if(sum>max)max=sum;

int N, M, arr[500][500], max, i, j, a, b, c, d;

void shape1(void) {
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M-3 ; j++) {
			a=arr[i][j];
			b=arr[i][j+1];
			c=arr[i][j+2];
			d=arr[i][j+3];
			update
		}
	for(i=0 ; i<N-3 ; i++)
		for(j=0 ; j<M ; j++) {
			a=arr[i][j];
			b=arr[i+1][j];
			c=arr[i+2][j];
			d=arr[i+3][j];
			update
		}
}
void shape2(void) {
	for(i=0 ; i<N-2 ; i++)
		for(j=0 ; j<M-2 ; j++) {
			a=arr[i][j];
			b=arr[i][j+1];
			c=arr[i+1][j];
			d=arr[i+1][j+1];
			update
		}
}
void shape3(void) {
	for(i=0 ; i<N-2 ; i++)
		for(j=0 ; j<M-1 ; j++) {
			a=arr[i][j];
			b=arr[i+1][j];
			c=arr[i+2][j];
			d=arr[i+2][j+1];
			update
			d=arr[i][j+1];
			update
			b=arr[i][j+1];
			c=arr[i+1][j+1];
			d=arr[i+2][j+1];
			update
			a=arr[i+2][j];
			update
		}
	for(i=0 ; i<N-1 ; i++)
		for(j=0 ; j<M-2 ; j++) {
			a=arr[i][j];
			b=arr[i][j+1];
			c=arr[i][j+2];
			d=arr[i+1][j+2];
			update
			d=arr[i+1][j];
			update
			b=arr[i+1][j];
			c=arr[i+1][j+1];
			d=arr[i+1][j+2];
			update
			a=arr[i][j+2];
			update
		}
}
void shape4(void) {
	for(i=0 ; i<N-2 ; i++)
		for(j=0 ; j<M-1 ; j++) {
			a=arr[i][j];
			b=arr[i+1][j];
			c=arr[i+1][j+1];
			d=arr[i+2][j+1];
			update
			a=arr[i+2][j];
			d=arr[i][j+1];
			update
		}
	for(i=0 ; i<N-1 ; i++)
		for(j=0 ; j<M-2 ; j++) {
			a=arr[i][j];
			b=arr[i][j+1];
			c=arr[i+1][j+1];
			d=arr[i+1][j+2];
			update
			a=arr[i][j+2];
			d=arr[i+1][j];
			update
		}
}
void shape5(void) {
	for(i=0 ; i<N-1 ; i++)
		for(j=0 ; j<M-2 ; j++) {
			a=arr[i][j];
			b=arr[i][j+1];
			c=arr[i][j+2];
			d=arr[i+1][j+1];
			update
			a=arr[i+1][j];
			c=arr[i+1][j+2];
			update
		}
	for(i=0 ; i<N-2 ; i++)
		for(j=0 ; j<M-1 ; j++) {
			a=arr[i][j];
			b=arr[i+1][j];
			c=arr[i+1][j+1];
			d=arr[i+2][j];
			update
			a=arr[i][j+1];
			d=arr[i+2][j+1];
			update
		}
}

int main(void) {
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<M ; j++)
			scanf("%d", &arr[i][j]);
	shape1();
	shape2();
	shape3();
	shape4();
	shape5();
	printf("%d", max);
	return 0;
}
