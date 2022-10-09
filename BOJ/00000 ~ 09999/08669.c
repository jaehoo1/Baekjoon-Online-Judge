# include <stdio.h>
# include <stdbool.h>

int main(void) {
	bool set[1000001]={false, };
	int n, g, r, i, cou=0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &g, &r);
		set[r]=true;
	}
	for(i=0 ; i<=1000000 ; i++)
		if(set[i])
			cou++;
	printf("%d", cou);
	return 0;
}