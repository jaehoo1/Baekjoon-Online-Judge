# include <stdio.h>
# include <string.h>

void swap(char *a, char *b) {
	char temp=*a;
	*a=*b;
	*b=temp;
}
void reverse(char *str) {
	int i, len=strlen(str);
	for(i=0 ; i<len/2 ; i++)
		swap(&str[i], &str[len-i-1]);
}
int palindrom(char *str) {
	char temp[10];
	strcpy(temp, str);
	reverse(temp);
	return !strcmp(temp, str);
}

int main(void) {
	int n, temp;
	char str[10];
	long long sum=0;
	scanf("%d", &n);
	while(n--) {
		scanf("%s", str);
		if(palindrom(str)) {
			sscanf(str, "%d", &temp);
			sum+=temp;
		}
	}
	printf("%lld", sum);
	return 0;
}
