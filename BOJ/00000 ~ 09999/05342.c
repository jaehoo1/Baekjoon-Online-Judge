# include <stdio.h>
# include <string.h>

int main(void) {
	double cost=0;
	char str[10];
	while(scanf("%s", str)) {
		if(!strcmp(str, "EOI"))
			break;
		else if(!strcmp(str, "Paper"))
			cost+=57.99;
		else if(!strcmp(str, "Printer"))
			cost+=120.50;
		else if(!strcmp(str, "Planners"))
			cost+=31.25;
		else if(!strcmp(str, "Binders"))
			cost+=22.50;
		else if(!strcmp(str, "Calendar"))
			cost+=10.95;
		else if(!strcmp(str, "Notebooks"))
			cost+=11.20;
		else if(!strcmp(str, "Ink"))
			cost+=66.95;
	}
	printf("$%.2lf", cost);
	return 0;
}