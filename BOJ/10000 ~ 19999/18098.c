# include <stdio.h>

typedef enum { false, true }bool;

int main(void) {
	int N, i, num, cou=0;
	bool arr[100000]={0, };
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &num);
		if(num<=N)
			arr[num-1]=1;
	}
	for(i=0 ; i<N ; i++)
		if(arr[i])cou++;
	printf("%d", cou);
	return 0;
}
