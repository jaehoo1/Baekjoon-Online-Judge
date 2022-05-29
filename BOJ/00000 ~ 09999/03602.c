# include <stdio.h>

void swap(int *a, int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(void) {
	int b, w, s=1, ss, S=0;
	scanf("%d%d", &b, &w);
	if(b>w)swap(&b, &w);	//b<=w
	while(s) {
		ss=s*s/2;
		if(b>=ss&&w>=s*s-ss)
			S=s;
		else
			break;
		s++;
	}
	if(S)printf("%d", S);
	else	puts("Impossible");
	return 0;
}
