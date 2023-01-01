# include <stdio.h>

int main(void) {
	int a[4], b, i, min=100, minidx;
	for(i=0 ; i<4 ; i++) {
		scanf("%d", &a[i]);
		if(a[i]<min) {
			min=a[i];
			minidx=i;
		}
	}
	scanf("%d", &b);
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) {
		puts("1");
		return 0;
	}
	a[minidx]+=b;
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) {
		puts("1");
		return 0;
	}
	puts("0");
	return 0;
}