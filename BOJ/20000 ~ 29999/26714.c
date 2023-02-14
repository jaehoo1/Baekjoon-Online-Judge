# include <stdio.h>
# include <stdbool.h>

int main(void) {
	int n, i, j, score=0;
	bool getscore;
	char str[101];
	scanf("%d%s", &n, str);
	for(i=0 ; i<n ; i+=n/10) {
		getscore=true;
		for(j=i ; j<i+n/10 ; j++)
			if(str[j]=='N')
				getscore=false;
		if(getscore)
			score++;
	}
	printf("%d", score);
	return 0;
}