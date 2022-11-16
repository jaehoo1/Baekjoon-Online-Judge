# include <stdio.h>
# include <stdlib.h>

typedef struct { int id, score, rank; }student;

int desscore(const student *a, const student *b) {
	if(a->score>b->score)
		return -1;
	else if(a->score<b->score)
		return 1;
	else
		return 0;
}
int ascid(const student *a, const student *b) {
	if(a->id<b->id)
		return -1;
	else if(a->id>b->id)
		return 1;
	else
		return 0;
}

int main(void) {
	int N, i, j, rank=1;
	student arr[100000];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		arr[i].id=i;
		scanf("%d", &arr[i].score);
	}
	qsort(arr, N, sizeof(student), (int(*)(const void*, const void*))desscore);
	for(i=0 ; i<N ; ) {
		arr[i].rank=rank;
		for(j=i+1 ; j<N&&arr[i].score==arr[j].score ; j++)
			arr[j].rank=rank;
		rank+=j-i;
		i=j;
	}
	qsort(arr, N, sizeof(student), (int(*)(const void*, const void*))ascid);
	for(i=0 ; i<N ; i++)
		printf("%d\n", arr[i].rank);
	return 0;
}