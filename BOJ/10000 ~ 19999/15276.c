# include <stdio.h>
# include <string.h>
# include <math.h>

void swap(char *a, char *b) {
	char temp=*a;
	*a=*b;
	*b=temp;
}
void reverse(char *str) {
	int i;
	for(i=0 ; i<3 ; i++)
		swap(&str[i], &str[6-i-1]);
}
int ispalindrom(int x) {
	char str[7], temp[7];
	int i;
	sprintf(str, "%d", x);
	strcpy(temp, str);
	reverse(temp);
	return !strcmp(temp, str);
}

int main(void) {
	int N, i, ptr=0, arr[900], num, min, temp;
	for(i=100000 ; i<1000000 ; i++)
		if(ispalindrom(i))
			arr[ptr++]=i;
	scanf("%d", &N);
	while(N--) {
		min=1000000000;
		scanf("%d", &num);
		for(i=0 ; i<ptr ; i++)
			if(abs(arr[i]-num)<min) {
				min=abs(arr[i]-num);
				temp=arr[i];
			}
		printf("%d\n", temp);
	}
	return 0;
}
