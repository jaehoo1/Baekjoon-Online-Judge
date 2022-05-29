# include <stdio.h>

int main(void) {
	double C, w, l, S=0;
	int L;
	scanf("%lf%d", &C, &L);
	while(L--) {
		scanf("%lf%lf", &w, &l);
		S+=w*l;
	}
	printf("%.7lf", C*S);
	return 0;
}
