# include <stdio.h>

int main(void) {
	int T;
	double cm, kg, bmi;
	scanf("%d", &T);
	while(T--) {
		scanf("%lf%lf", &cm, &kg);
		bmi=kg/(cm*cm)*10000;
		if(cm<140.1)
			puts("6");
		else if(cm<146)
			puts("5");
		else if(cm<159)
			puts("4");
		else if(cm<161)
			if(bmi>=16&&bmi<35)
				puts("3");
			else
				puts("4");
		else if(cm<204) {
			if(bmi>=20&&bmi<25)
				puts("1");
			else if(bmi>=18.5&&bmi<20||bmi>=25&&bmi<30)
				puts("2");
			else if(bmi>=16&&bmi<18.5||bmi>=30&&bmi<35)
				puts("3");
			else if(bmi<16||bmi>=35)
				puts("4");
		} else if(cm>=204)
			puts("4");
	}
	return 0;
}