# include <stdio.h>
# include <math.h>

int main(void) {
	int i;
	double t[10], avg=0, s=0;
	for(i=0 ; i<10 ; i++) {
		scanf("%lf", &t[i]);
		avg+=t[i];
	}
	avg/=10;
	for(i=0 ; i<10 ; i++)
		s+=pow(t[0]-avg, 2);
	s=sqrt(s/9);
	if(s<=1)
		puts("COMFY");
	else
		puts("NOT COMFY");
	return 0;
}
