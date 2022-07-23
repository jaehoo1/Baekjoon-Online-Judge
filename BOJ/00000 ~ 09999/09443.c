# include <stdio.h>

int main(void) {
	int n, arr[27]={0, }, i;
	char str[31];
	scanf("%d", &n);
	for(i=0 ; i<n ; i++) {
		scanf("%s", str);
		arr[str[0]-'A']++;
	}
	for(i=0 ; arr[i] ; i++);
	printf("%d", i);
	return 0;
}