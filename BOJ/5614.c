# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
	char name[6];
	int num;
}data;

int datacmp(const data *a, const data *b) {
	int lena=strlen(a->name), lenb=strlen(b->name);
	if(lena<lenb)return -1;
	else if(lena>lenb)return 1;
	return strcmp(a->name, b->name);
}

int main(void) {
	data *arr, temp, *p;
	int n, i, ptr=0;
	scanf("%d", &n);
	arr=(data*)malloc(sizeof(data)*n);
	for(i=0 ; i<n ; i++) {
		scanf("%s%d", temp.name, &temp.num);
		p=(data*)bsearch(temp.name, arr, ptr, sizeof(data), (int(*)(const void*, const void*))datacmp);
		if(p)
			p->num+=temp.num;
		else {
			strcpy(arr[ptr].name, temp.name);
			arr[ptr++].num=temp.num;
			qsort(arr, ptr, sizeof(data), (int(*)(const void*, const void*))datacmp);
		}
	}
	for(i=0 ; i<ptr ; i++)
		printf("%s %d\n", arr[i].name, arr[i].num);
	return 0;
}
