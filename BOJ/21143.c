# include <stdio.h>

int main(void) {
	char str[51];
	int i, arr[26]={0, };
	scanf("%s", str);
	for(i=0 ; str[i] ; i++)
		arr[str[i]-'a']++;
	for(i=0 ; i<26 ; i++)
		if(arr[i]>=2) {
			puts("0");
			return 0;
		}
	puts("1");
	return 0;
}
