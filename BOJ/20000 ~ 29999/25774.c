# include <stdio.h>

int main(void) {
	int d, m, y, n, dd, mm, yy;
	scanf("%d%d%d%d%d%d%d", &d, &m, &y, &n, &dd, &mm, &yy);
	while(d!=dd||m!=mm||y!=yy) {
		d++;
		n++;
		if(d>30) {
			d=1;
			m++;
		}
		if(m>12) {
			m=1;
			y++;
		}
		if(n>7)
			n=1;
	}
	printf("%d", n);
	return 0;
}