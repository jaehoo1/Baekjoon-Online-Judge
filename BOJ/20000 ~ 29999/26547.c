# include <stdio.h>
# include <string.h>

void init(char arr[100][101]) {
	int i, j;
	for(i=0 ; i<100 ; i++)
		for(j=0 ; j<101 ; j++)
			arr[i][j]=' ';
}

int main(void) {
	int k, i, j, len;
	char word[101], arr[100][101];
	scanf("%d", &k);
	while(k--) {
		init(arr);
		scanf("%s", word);
		len=strlen(word);
		for(i=0 ; i<len ; i++) {
			arr[0][i]=arr[len-1][len-1-i]=arr[i][0]=arr[len-1-i][len-1]=word[i];
			arr[i][len]=0;
		}
		for(i=0 ; i<len ; i++)
			puts(arr[i]);
	}
	return 0;
}