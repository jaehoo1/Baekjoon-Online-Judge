# include <stdio.h>
# include <string.h>

int length(int A, int B) {
	int len=0;
	while(A<=B) {
		if(A<10)len++;
		else if(A<100)len+=2;
		else if(A<1000)len+=3;
		A++;
	}
	return len;
}

int main(void) {
	char str[2890], temp[4];
	int A, B, len, i, j, k;
	scanf("%s", str);
	len=strlen(str);
	for(i=1 ; i<=3&&i<=len ; i++) {
		for(k=0 ; k<i ; k++)
			temp[k]=str[k];
		temp[k]=0;
		sscanf(temp, "%d", &A);
		for(j=1 ; j<=3&&j<=len ; j++) {
			for(k=0 ; k<j ; k++)
				temp[k]=str[len+k-j];
			temp[k]=0;
			sscanf(temp, "%d", &B);
			if(length(A, B)==len) {
				printf("%d %d", A, B);
				return 0;
			}
		}
	}
	return 0;
}
