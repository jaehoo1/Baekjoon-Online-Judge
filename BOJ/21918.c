# include <stdio.h>

typedef enum {
	false, true
}bool;

bool arr[4001];

void f1(int i, int x) { arr[i]=x; }
void f2(int l, int r) {
	for( ; l<=r ; l++)
		arr[l]=!arr[l];
}
void f3(int l, int r) {
	for( ; l<=r ; l++)
		arr[l]=false;
}
void f4(int l, int r) {
	for( ; l<=r ; l++)
		arr[l]=true;
}

int main(void) {
	int N, M, i, a, b, c;
	scanf("%d%d", &N, &M);
	for(i=1 ; i<=N ; i++)
		scanf("%d", &arr[i]);
	while(M--) {
		scanf("%d%d%d", &a, &b, &c);
		if(a==1)f1(b, c);
		else if(a==2)f2(b, c);
		else if(a==3)f3(b, c);
		else if(a==4)f4(b, c);
	}
	for(i=1 ; i<=N ; i++)
		printf("%d ", arr[i]);
	return 0;
}
