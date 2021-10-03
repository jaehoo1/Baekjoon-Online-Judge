# include <stdio.h>

typedef struct {
	int x, y;
}pos;

int ccw(pos A, pos B, pos C) {
	int a=A.x*B.y+B.x*C.y+C.x*A.y, b=B.x*A.y+C.x*B.y+A.x*C.y;
	if(a-b>0)return 1;
	else if(a-b<0)return -1;
	return 0;
}

int main(void) {
	pos A, B, C, D;
	scanf("%d%d%d%d%d%d%d%d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);
	if(ccw(A, B, C)*ccw(A, B, D)<0)puts("1");
	else	puts("0");
	return 0;
}
