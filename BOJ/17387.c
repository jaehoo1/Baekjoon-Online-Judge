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
int islined(pos A, pos B, pos C) {
	if(A.x<B.x)
		return B.x<C.x;
	else if(B.x<A.x)
		return C.x<B.x;
	if(A.y<B.y)
		return B.y<C.y;
	else if(B.y<A.y)
		return C.y<B.y;
}

int main(void) {
	pos A, B, C, D;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);
	if(ccw(A, B, C)*ccw(A, B, D)==0&&ccw(C, D, A)*ccw(C, D, B)==0)
		if((islined(A, B, C)&&islined(A, B, D))||(islined(B, A, C)&&islined(B, A, D)))puts("0");
		else	puts("1");
	else if(ccw(A, B, C)*ccw(A, B, D)<=0&&ccw(C, D, A)*ccw(C, D, B)<=0)puts("1");
	else	puts("0");
	return 0;
}
