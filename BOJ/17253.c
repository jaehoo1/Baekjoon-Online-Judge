# include <stdio.h>

long long pow3(long long x) {
	unsigned long long res=1;
	while(res*3<=x)
		res*=3;
	return res;
}

int main(void) {
	int ptr=0, flag=1;
	long long N, arr[40], temp;
	scanf("%lld", &N);
	if(!N) {
		puts("NO");
		return 0;
	}
	while(N) {
		temp=pow3(N);
		if(ptr&&arr[ptr-1]==temp) {
			flag=0;
			break;
		}
		arr[ptr++]=temp;
		N-=temp;
	}
	if(!N&&flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}
