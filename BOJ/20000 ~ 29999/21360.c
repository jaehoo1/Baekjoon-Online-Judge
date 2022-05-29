# include <stdio.h>

int main(void) {
	int N, i, arr[1000000], ptr=0, min=1000000;
	char str[1000001];
	scanf("%d", &N);
	scanf("%s", str);
	for(i=0 ; str[i] ; i++)
		if(str[i]=='.')
			arr[ptr++]=i;
	for(i=0 ; i<ptr-1 ; i++)
		if(arr[i+1]-arr[i]<min)
			min=arr[i+1]-arr[i];
	printf("%d", min-1);
	return 0;
}
