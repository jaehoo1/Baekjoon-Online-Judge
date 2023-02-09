# include <stdio.h>
# include <stdlib.h>

typedef struct {
	char name[21];
	int like;
}friend;

int cmp(const friend *a, const friend *b) { return a->like<b->like; }

int main(void) {
	friend arr[500];
	int n, m, i;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &m);
		for(i=0 ; i<m ; i++)
			scanf("%s%d", arr[i].name, &arr[i].like);
		qsort(arr, m, sizeof(friend), (int(*)(const void*, const void*))cmp);
		for(i=0 ; i<m-1 ; i++)
			printf("%s, ", arr[i].name);
		puts(arr[i].name);
	}
	return 0;
}