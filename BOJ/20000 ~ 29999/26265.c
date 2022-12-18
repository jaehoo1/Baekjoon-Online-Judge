# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct {
	char mentor[21], mentee[21];
}pair;

int paircmp(const pair *a, const pair *b) {
	if(!strcmp(a->mentor, b->mentor))
		return -strcmp(a->mentee, b->mentee);
	return strcmp(a->mentor, b->mentor);
}

int main(void) {
	pair arr[100000];
	int N, i;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%s%s", arr[i].mentor, arr[i].mentee);
	qsort(arr, N, sizeof(pair), (int(*)(const void *, const void *))paircmp);
	for(i=0 ; i<N ; i++)
		printf("%s %s\n", arr[i].mentor, arr[i].mentee);
	return 0;
}