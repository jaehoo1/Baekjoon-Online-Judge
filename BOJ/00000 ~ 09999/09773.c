# include <stdio.h>

int main(void) {
	int N, sum, last, i, res;
	char str[14];
	scanf("%d", &N);
	while(N--) {
		sum=0;
		scanf("%s", str);
		for(i=0 ; i<13 ; i++)
			sum+=str[i]-'0';
		sscanf(&str[10], "%d", &last);
		last*=10;
		res=sum+last;
		if(res<1000)
			res+=1000;
		printf("%04d\n", res%10000);
	}
	return 0;
}