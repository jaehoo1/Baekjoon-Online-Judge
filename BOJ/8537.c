# include <stdio.h>

void init(int *arr) {
	int i;
	for(i=0 ; i<26 ; i++)
		arr[i]=0;
}

int main(void) {
	int N, i, arr[26], cou, max=0;
	char str[21];
	scanf("%d", &N);
	while(N--) {
		cou=0;
		init(arr);
		scanf("%s", str);
		for(i=0 ; str[i] ; i++)
			arr[str[i]-'a']++;
		for(i=0 ; i<26 ; i++)
			if(arr[i])
				cou++;
		if(cou>max)
			max=cou;
	}
	printf("%d", max);
	return 0;
}
