# include <stdio.h>

int main(void) {
	char str[61];
	int cou[26]={0, }, even=1, odd=1, i;
	scanf("%s", str);
	for(i=0 ; str[i] ; i++)
		cou[str[i]-'a']++;
	for(i=0 ; i<26 ; i++) {
		if(!cou[i])
			continue;
		if(cou[i]%2)
			even=0;
		else
			odd=0;
	}
	if(even)
		puts("0");
	else if(odd)
		puts("1");
	else
		puts("0/1");
	return 0;
}