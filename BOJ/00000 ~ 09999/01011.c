# include <stdio.h>
# include <math.h>

int ifpow(const int N) {
	int temp=sqrt(N);
	if(N==temp*temp)
		return 1;
	return 0;
}
long long lpow(const int N) {
	int i=1;
	while(pow(i+1, 2)<N)
		i++;
	return pow(i, 2);
}
long long hpow(const int N) {
	int i=1;
	while(pow(i, 2)<N)
		i++;
	return pow(i, 2);
}

int main(void) {
	int T;
	long long x, y, res;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &x, &y);
		y-=x;
		if(ifpow(y))
			res=sqrt(y)*2-1;
		else if((lpow(y)+1+hpow(y))/2<=y) {
			res=(int)sqrt(y)*2+1;
		}
		else
			res=(int)sqrt(y)*2;
		printf("%lld\n", res);
	}
	return 0;
}
