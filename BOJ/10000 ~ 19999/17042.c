# include <stdio.h>
# include <stdbool.h>

int main(void) {
	bool wand[26]={false, }, visited[26]={false, };
	int N, i, cou=1;
	char first, Z1, Z2;
	scanf("%c", &first);
	visited[first-'A']=true;
	wand[first-'A']=true;
	scanf("%d", &N);
	while(N--) {
		getchar();
		scanf("%c %c", &Z1, &Z2);
		if(wand[Z2-'A']) {
			wand[Z2-'A']=false;
			wand[Z1-'A']=true;
			if(!visited[Z1-'A']) {
				visited[Z1-'A']=true;
				cou++;
			}
		}
	}
	for(i=0 ; i<26 ; i++)
		if(wand[i])
			printf("%c\n", i+'A');
	printf("%d", cou);
	return 0;
}