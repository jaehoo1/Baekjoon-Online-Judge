# include <stdio.h>
# include <math.h>

double absolute(double d) {
	return d<0?-d:d;
}

int main(void) {
	int D, E, i;
	double min, temp;
	while(scanf("%d%d", &D, &E)) {
		if(!D&&!E)
			return 0;
		min=abs(D-E);
		for(i=1 ; i<D ; i++) {
			temp=absolute(sqrt(pow(D-i, 2)+pow(i, 2))-E);
			if(temp<min)
				min=temp;
		}
		printf("%.4lf\n", min);
	}
	return 0;
}
