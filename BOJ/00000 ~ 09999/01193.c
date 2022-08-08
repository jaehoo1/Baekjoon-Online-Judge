# include <stdio.h>

int main(void) {
	int X, floor=0, vertex=0;
	scanf("%d", &X);
	while(vertex<X)
		vertex+=++floor;
	if(floor%2)
		printf("%d/%d", vertex+1-X, X-vertex+floor);
	else
		printf("%d/%d", X-vertex+floor, vertex+1-X);
	return 0;
}