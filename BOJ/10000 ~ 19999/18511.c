# include <stdio.h>

int N, K, arr[3], max;
char str[11];

void recur(int depth) {
	int num, i;
	for(i=0 ; i<K ; i++) {
		str[depth]=arr[i]+'0';
		str[depth+1]=0;
		sscanf(str, "%d", &num);
		if(num>max&&num<=N)
			max=num;
		if(depth<10)
			recur(depth+1);
	}
}

int main(void) {
	int i;
	scanf("%d%d", &N, &K);
	for(i=0 ; i<K ; i++)
		scanf("%d", &arr[i]);
	recur(0);
	printf("%d", max);
	return 0;
}