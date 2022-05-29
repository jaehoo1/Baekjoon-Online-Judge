# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int num, cou;
}data;

int datacmp(const data *a, const data *b) {
	if(a->cou>b->cou)return -1;
	else if(a->cou<b->cou)return 1;
	else
		if(a->num<b->num)return -1;
		else if(a->num>b->num)return 1;
		else	return 0;
}

int main(void) {
	data arr[100]={0, };
	int n, m, i, j, temp;
	scanf("%d%d", &n, &m);
	for(i=0 ; i<m ; i++)
		arr[i].num=i+1;
	for(i=0 ; i<n ; i++) {
		for(j=0 ; j<m ; j++) {
			scanf("%d", &temp);
			if(temp)
				arr[j].cou++;
		}
	}
	qsort(arr, m, sizeof(data), (int(*)(const void*, const void*))datacmp);
	for(i=0 ; i<m ; i++)
		printf("%d ", arr[i].num);
	return 0;
}
