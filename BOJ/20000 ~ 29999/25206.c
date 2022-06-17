# include <stdio.h>
# include <string.h>

int main(void) {
	int N=20, count=0;
	double score, sum=0;
	char str[51], grade[3];
	while(N--) {
		scanf("%s%lf%s", str, &score, grade);
		if(grade[0]=='P')
			continue;
		count+=score;
		if(!strcmp(grade, "A+"))
			sum+=score*4.5;
		else if(!strcmp(grade, "A0"))
			sum+=score*4;
		else if(!strcmp(grade, "B+"))
			sum+=score*3.5;
		else if(!strcmp(grade, "B0"))
			sum+=score*3;
		else if(!strcmp(grade, "C+"))
			sum+=score*2.5;
		else if(!strcmp(grade, "C0"))
			sum+=score*2;
		else if(!strcmp(grade, "D+"))
			sum+=score*1.5;
		else if(!strcmp(grade, "D0"))
			sum+=score;
	}
	printf("%.5lf", sum/count);
	return 0;
}