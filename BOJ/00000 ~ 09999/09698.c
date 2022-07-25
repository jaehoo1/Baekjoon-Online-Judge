# include <stdio.h>

int main(void) {
	int T, t, H, M;
	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		scanf("%d%d", &H, &M);
		M-=45;
		if(M<0) {
			H--;
			M+=60;
		}
		if(H<0)
			H+=24;
		printf("Case #%d: %d %d\n", t, H, M);
	}
	return 0;
}