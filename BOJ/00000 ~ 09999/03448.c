# include <stdio.h>
# include <string.h>

int main(void) {
	int N, R, A, i, ptr;
	char str[101], flat[33];
	scanf("%d", &N);
	getchar();
	while(N--) {
		R=0;A=0;
		while(1) {
			gets(str);
			if(!str[0])
				break;
			A+=strlen(str);
			for(i=0 ; str[i] ; i++)
				if(str[i]!='#')
					R++;
		}
		printf("Efficiency ratio is ");
		sprintf(flat, "%.1lf", (double)R/A*100);
		for(i=0 ; flat[i]!='.' ; i++);
		ptr=i;
		for(i=0 ; i<ptr ; i++)
			printf("%c", flat[i]);
		if(flat[ptr+1]!='0')
			printf(".%c", flat[ptr+1]);
		puts("%.");
	}
	return 0;
}
