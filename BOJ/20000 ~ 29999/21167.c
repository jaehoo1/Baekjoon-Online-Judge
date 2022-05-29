# include <stdio.h>
# include <math.h>

int main(void) {
	double R, S;
	char str[11]={'0'};
	while(~scanf("%lf%s", &R, &str[1])) {
		sscanf(str, "%lf", &S);
		printf("%.0lf\n", sqrt(((R*(S+0.16)))/0.067));
	}
	return 0;
}
