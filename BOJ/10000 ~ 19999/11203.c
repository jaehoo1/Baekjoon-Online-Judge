# include <stdio.h>
# include <math.h>

int main(void) {
	int H, argc, node=1, i;
	char path[31];
	argc=scanf("%d%s", &H, path);
	if(argc==1) {
		printf("%d", (int)pow(2, H+1)-1);
		return 0;
	}
	for(i=0 ; path[i] ; i++) {
		node*=2;
		if(path[i]=='R')
			node++;
	}
	printf("%d", (int)pow(2, H+1)-node);
	return 0;
}