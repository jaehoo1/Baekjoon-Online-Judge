# include <stdio.h>
# include <stdbool.h>

int main(void) {
	int n, y, m, d;
	bool vote;
	scanf("%d", &n);
	while(n--) {
		vote=false;
		scanf("%d%d%d", &y, &m, &d);
		if(2007-y>18)
			vote=true;
		else if(2007-y==18)
			if(m<2)
				vote=true;
			else if(m==2)
				if(d<=27)
					vote=true;
		puts(vote?"Yes":"No");
	}
	return 0;
}