# include <stdio.h>

int main(void) {
	double sum;
	char str[201];
	int i, cou;
	while(scanf("%s", str)) {
		if(str[0]=='*')break;
		sum=0;
		cou=0;
		for(i=0 ; str[i] ; i++)
			if(str[i]=='/') {
				if(sum==1)
					cou++;
				sum=0;
			} else if(str[i]=='W')sum+=1;
			else if(str[i]=='H')sum+=0.5;
			else if(str[i]=='Q')sum+=0.25;
			else if(str[i]=='E')sum+=0.125;
			else if(str[i]=='S')sum+=0.0625;
			else if(str[i]=='T')sum+=0.03125;
			else if(str[i]=='X')sum+=0.015625;
		printf("%d\n", cou);
	}
	return 0;
}
