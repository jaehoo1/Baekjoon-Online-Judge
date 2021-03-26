# include <stdio.h>
# include <string.h>

int main(void) {
	int t, p, n, i;
	char name[20][21], start[21];
	scanf("%d", &t);
	while(t--) {
		p=0;
		while(scanf("%s", name[p++]))
			if(getchar()=='\n')break;
		scanf("%s", start);
		i=0;
		while(strcmp(name[i], start))i++;
		scanf("%d", &n);
		n--;
		while(n--) {
			i++;
			if(i==p)
				i=0;
		}
		printf("%s\n", name[i]);
	}
	return 0;
}
