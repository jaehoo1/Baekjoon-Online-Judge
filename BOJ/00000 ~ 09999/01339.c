# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
	char alp;
	int weight;
}data;

int datacmp(const data *a, const data *b) {
	if(a->weight>b->weight)return -1;
	else if(a->weight<b->weight)return 1;
	else	return a->alp>b->alp;
}
int pow10(int n) {
	int i, res=1;
	for(i=0 ; i<n ; i++)
		res*=10;
	return res;
}

int main(void) {
	int N, i, len, sum=0;
	data arr[26];
	char str[9];
	for(i=0 ; i<26 ; i++) {
		arr[i].alp='A'+i;
		arr[i].weight=0;
	}
	scanf("%d", &N);
	while(N--) {
		scanf("%s", str);
		len=strlen(str);
		for(i=0 ; i<len ; i++)
			arr[str[i]-'A'].weight+=pow10(len-1-i);
	}
	qsort(arr, 26, sizeof(data), (int(*)(const void*, const void*))datacmp);
	for(i=0 ; i<9 ; i++)
		sum+=arr[i].weight*(9-i);
	printf("%d", sum);
	return 0;
}
