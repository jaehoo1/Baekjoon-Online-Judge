# include <stdio.h>

int main(void) {
	int T, i, j, cou, error;
	char str[65];
	scanf("%d", &T);
	while(T--) {
		error=0;
		scanf("%s", str);
		for(i=0 ; str[i] ; i+=8) {
			cou=0;
			for(j=i ; j<i+7 ; j++)
				if(str[j]=='1')
					cou++;
			if((str[j]=='0'&&cou%2)||(str[j]=='1'&&cou%2==0))
				error++;
		}
		printf("%d\n", error);
	}
	return 0;
}