# include <stdio.h>

int main(void) {
	int R, C, i, j, cou[5]={0, }, temp;
	char arr[50][51];
	scanf("%d%d", &R, &C);
	for(i=0 ; i<R ; i++)
		scanf("%s", arr[i]);
	for(i=0 ; i<R-1 ; i++)
		for(j=0 ; j<C-1 ; j++) {
			if(arr[i][j]=='#'||arr[i][j+1]=='#'||arr[i+1][j]=='#'||arr[i+1][j+1]=='#')
				continue;
			temp=0;
			if(arr[i][j]=='X')temp++;
			if(arr[i][j+1]=='X')temp++;
			if(arr[i+1][j]=='X')temp++;
			if(arr[i+1][j+1]=='X')temp++;
			cou[temp]++;
		}
	for(i=0 ; i<5 ; i++)
		printf("%d\n", cou[i]);
	return 0;
}
