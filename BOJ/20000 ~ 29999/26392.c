# include <stdio.h>

int main(void) {
	int n, r, s, max, min, i, j;
	char str[50][51];
	scanf("%d%d%d", &n, &r, &s);
	while(n--) {
		max=0;
		min=50;
		for(i=0 ; i<r ; i++)
			scanf("%s", str[i]);
		for(i=0 ; i<r ; i++)
			for(j=0 ; j<s ; j++)
				if(str[i][j]=='#') {
					if(i>max)
						max=i;
					if(i<min)
						min=i;
				}
		printf("%d\n", max-min);
	}
	return 0;
}