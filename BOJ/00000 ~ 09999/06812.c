# include <stdio.h>

int main(void) {
	int time, res, dif[7]={0, -300, -200, -100, 0, 100, 130}, i;
	char str[7][11]={"Ottawa", "Victoria", "Edmonton", "Winnipeg", "Toronto", "Halifax", "St. John's"};
	scanf("%d", &time);
	for(i=0 ; i<7 ; i++) {
		res=time+dif[i];
		if(res%100>=60) {
			res+=100;
			res-=60;
		}
		if(res<0)
			res+=2400;
		if(res>=2400)
			res-=2400;
		printf("%d in %s\n", res, str[i]);
	}
	return 0;
}