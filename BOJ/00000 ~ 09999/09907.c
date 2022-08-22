# include <stdio.h>

int main(void) {
	char NICE[8], weight[8]="2765432", mod[12]="JABCDEFGHIZ";
	int i, sum=0;
	scanf("%s", NICE);
	for(i=0 ; i<7 ; i++)
		sum+=(NICE[i]-'0')*(weight[i]-'0');
	printf("%c", mod[sum%11]);
	return 0;
}