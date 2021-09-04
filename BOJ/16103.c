# include <stdio.h>
# include <string.h>

int main(void) {
	int N;
	long long K;
	char str[100001], temp1[25001], temp2[75001];
	scanf("%d%lld%s", &N, &K, str);
	K%=3;
	while(K--) {
		strcpy(temp1, &str[N-N/4]);
		strcpy(temp2, &str[N/4]);
		temp2[N/2]=0;
		strcpy(&str[N/4], temp1);
		strcpy(&str[N/2], temp2);
	}
	puts(str);
	return 0;
}
