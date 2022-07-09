# include <stdio.h>

int main(void) {
	char str[17];
	int i, num, sum=0;
	scanf("%s", str);
	for(i=0 ; i<16 ; i++)
		if(i%2)
			sum+=str[i]-'0';
		else {
			num=str[i]-'0';
			num*=2;
			if(num>=10)
				sum+=1+num%10;
			else
				sum+=num;
		}
	puts(sum%10?"NE":"DA");
	return 0;
}