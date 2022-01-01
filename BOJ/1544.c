# include <stdio.h>
# include <string.h>

int arr_len;
char arr[50][51];

int find(char *str) {
	int i;
	char temp[101];
	strcpy(temp, str);
	strcpy(&temp[strlen(temp)], str);
	for(i=0 ; i<arr_len ; i++)
		if(strlen(temp)==strlen(arr[i])*2&&strstr(temp, arr[i]))
			return 1;
	return 0;
}

int main(void) {
	int N;
	char str[51];
	scanf("%d", &N);
	while(N--) {
		scanf("%s", str);
		if(!find(str))
			strcpy(arr[arr_len++], str);
	}
	printf("%d", arr_len);
	return 0;
}
