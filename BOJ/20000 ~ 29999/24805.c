# include <stdio.h>

int main(void) {
	int a, b, h, cur=0, i=0;
	scanf("%d%d%d", &a, &b, &h);
	while(cur<h) {
		cur+=a;
		i++;
		if(cur>=h)
			break;
		cur-=b;
	}
	printf("%d", i);
	return 0;
}