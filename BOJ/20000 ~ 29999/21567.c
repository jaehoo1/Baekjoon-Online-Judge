# include <stdio.h>

int main(void) {
	char str[20];
	long long A=1, num;
	int arr[10]={0, }, i;
	for(i=0 ; i<3 ; i++) {
		scanf("%lld", &num);
		A*=num;
	}
	sprintf(str, "%lld", A);
	for(i=0 ; str[i] ; i++)
		arr[str[i]-'0']++;
	for(i=0 ; i<10 ; i++)
		printf("%d\n", arr[i]);
	return 0;
}
