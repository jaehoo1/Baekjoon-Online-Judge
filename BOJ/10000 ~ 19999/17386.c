# include <stdio.h>

typedef struct {
	long long x, y;
}pos;

int ccw(pos A, pos B, pos C) {
	long long a=A.x*B.y+B.x*C.y+C.x*A.y, b=B.x*A.y+C.x*B.y+A.x*C.y;
	if(a-b>0)return 1;
	else if(a-b<0)return -1;
	return 0;
}

int main(void) {
	pos A, B, C, D;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);
	if(ccw(A, B, C)*ccw(A, B, D)<0&&ccw(C, D, A)*ccw(C, D, B)<0)puts("1");
	else	puts("0");
	return 0;
}
