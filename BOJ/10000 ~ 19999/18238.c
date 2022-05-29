# include <stdio.h>
# include <string.h>

int right(char A, const char B) {
	int temp=0;
	while(A!=B) {
		A++;
		temp++;
		if(A>'Z')A='A';
	}
	return temp;
}
int left(char A, const char B) {
	int temp=0;
	while(A!=B) {
		A--;
		temp++;
		if(A<'A')A='Z';
	}
	return temp;
}

int main(void) {
	char str[102]={'A'};
	int i, len, res=0;
	scanf("%s", &str[1]);
	len=strlen(str);
	for(i=0 ; i<len-1 ; i++)
		res+=left(str[i], str[i+1])<right(str[i], str[i+1])?left(str[i], str[i+1]):right(str[i], str[i+1]);
	printf("%d", res);
	return 0;
}
