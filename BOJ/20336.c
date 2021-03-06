# include <stdio.h>

typedef struct {
	int d;
	char dish[42][21];
}data;

int main(void) {
	data arr[100];
	int n, i, j;
	scanf("%d", &n);
	for(i=0 ; i<n ; i++) {
		scanf("%d", &arr[i].d);
		for(j=0 ; j<arr[i].d ; j++)
			scanf("%s", arr[i].dish[j]);
	}
	printf("%d\n", arr[0].d);
	for(i=0 ; i<arr[0].d ; i++)
		printf("%s\n", arr[0].dish[i]);
	return 0;
}
