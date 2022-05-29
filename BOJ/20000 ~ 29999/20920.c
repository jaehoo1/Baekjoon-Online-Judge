# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct {
	char word[11];
	int cou, len;
}data;

int datacmp(const data *a, const data *b) {
	if(a->cou>b->cou)return -1;
	else if(a->cou<b->cou)return 1;
	else
		if(a->len>b->len)return -1;
		else if(a->len<b->len)return 1;
		else  return strcmp(a->word, b->word);
}
void datacpy(data *Dest, const data *Source) {
	strcpy(Dest->word, Source->word);
	Dest->cou=Source->cou;
	Dest->len=Source->len;
}

int main(void) {
	int N, M, i, j, len, ptr=0, final=0;
	char str[11];
	data *arr, *sort;
	scanf("%d%d", &N, &M);
	arr=(data*)malloc(sizeof(data)*N);
	sort=(data*)malloc(sizeof(data)*N);
	for(i=0 ; i<N ; i++) {
		scanf("%s", str);
		len=strlen(str);
		if(len>=M) {
			strcpy(arr[ptr].word, str);
			arr[ptr].len=len;
			arr[ptr++].cou=0;
		}
	}
	qsort(arr, ptr, sizeof(data), (int(*)(const void*, const void*))strcmp);
	for(i=0 ; i<ptr ; i++) {
		arr[i].cou=1;
		j=i+1;
		while(!strcmp(arr[i].word, arr[j].word)) {
			j++;
			arr[i].cou++;
		}
		i=j-1;
	}
	for(i=0 ; i<ptr ; i++)
		if(arr[i].cou)
			datacpy(&sort[final++], &arr[i]);
	qsort(sort, final, sizeof(data), (int(*)(const void*, const void*))datacmp);
	for(i=0 ; i<final ; i++)
		printf("%s\n", sort[i].word);
	return 0;
}
