# include <stdio.h>

int main(void) {
	int n, m, i, j;
	char adjectives[5][101], nouns[5][101];
	scanf("%d%d", &n, &m);
	for(i=0 ; i<n ; i++)
		scanf("%s", adjectives[i]);
	for(i=0 ; i<m ; i++)
		scanf("%s", nouns[i]);
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<m ; j++)
			printf("%s as %s\n", adjectives[i], nouns[j]);
	return 0;
}