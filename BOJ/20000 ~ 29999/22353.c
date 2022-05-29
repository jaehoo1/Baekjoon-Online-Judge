# include <stdio.h>

int main(void) {
	int a, d, k, ptr=0, time=0, i, j;
	double win[1000], sum=0, percent;
	scanf("%d%d%d", &a, &d, &k);
	win[ptr++]=(double)d/100;
	while(1) {
		win[ptr]=win[ptr-1]+win[ptr-1]*((double)k/100);
		ptr++;
		if(win[ptr-1]>=1) {
			win[ptr-1]=1;
			break;
		}
	}
	for(i=0 ; i<ptr ; i++) {
		percent=1;
		time+=a;
		for(j=0 ; j<i ; j++)
			percent*=1-win[j];
		percent*=win[j];
		sum+=(double)time*percent;
	}
	printf("%.7lf\n", sum);
	return 0;
}
