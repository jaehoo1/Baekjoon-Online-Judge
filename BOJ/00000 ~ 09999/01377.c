# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct { int num, idx; }data;

int datacmp(const data *a, const data *b) {
	if(a->num<b->num)return -1;
	else if(a->num>b->num)return 1;
	else
		if(a->idx<b->idx)return -1;
		else if(a->idx>b->idx)return 1;
		else	return 0;
}

int main(void) {
	int N, i, max=0;
	data org[500000], arr[500000], *ptr;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &org[i].num);
		org[i].idx=i;
		arr[i]=org[i];
	}
	qsort(arr, N, sizeof(data), (int(*)(const void*, const void*))datacmp);
	for(i=0 ; i<N ; i++) {
		ptr=(data*)bsearch(&org[i], arr, N, sizeof(data), (int(*)(const void*, const void*))datacmp)-arr;
		if(i-(int)ptr>max)
			max=i-(int)ptr;
	}
	printf("%d", max+1);
	return 0;
}
