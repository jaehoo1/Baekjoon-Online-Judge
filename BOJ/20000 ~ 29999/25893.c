# include <stdio.h>

int count_greater_than_10(int *arr) {
	int i, ret=0;
	for(i=0 ; i<3 ; i++)
		if(arr[i]>=10)
			ret++;
	return ret;
}

int main(void) {
	int n, arr[3], i, cou;
	scanf("%d", &n);
	while(n--) {
		for(i=0 ; i<3 ; i++)
			scanf("%d", &arr[i]);
		for(i=0 ; i<3 ; i++)
			printf("%d ", arr[i]);
		puts("");
		cou=count_greater_than_10(arr);
		if(!cou)
			puts("zilch");
		else if(cou==1)
			puts("double");
		else if(cou==2)
			puts("double-double");
		else if(cou==3)
			puts("triple-double");
		puts("");
	}
	return 0;
}