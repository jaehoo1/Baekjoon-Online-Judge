# include <stdio.h>

int main(void) {
	int t1, v1, t2, v2;
	scanf("%d%d%d%d", &t1, &v1, &t2, &v2);
	if(t2<0&&v2>=10) {
		puts("A storm warning for tomorrow!");
		puts("Be careful and stay home if possible!");
	} else if(t2<t1) {
		puts("MCHS warns! Low temperature");
		puts("is expected tomorrow.");
	} else if(v2>v1) {
		puts("MCHS warns! Strong wind");
		puts("is expected tomorrow.");
	} else
		puts("No message");
	return 0;
}
