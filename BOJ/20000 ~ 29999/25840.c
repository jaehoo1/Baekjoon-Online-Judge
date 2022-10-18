# include <stdio.h>
# include <stdbool.h>

int main(void) {
	bool set[13][32]={false, };
	int n, mm, dd, i, j, cou=0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d/%d", &mm, &dd);
		set[mm][dd]=true;
	}
	for(i=1 ; i<=12 ; i++)
		for(j=1 ; j<=31 ; j++)
			if(set[i][j])
				cou++;
	printf("%d", cou);
	return 0;
}