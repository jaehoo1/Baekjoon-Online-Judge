# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct { char str[202]; }file;

int filecmp(const file *a, const file *b) { return strcmp(a->str, b->str); }

int main(void) {
	int N, i, j, cou;
	file arr[50000];
	char temp[202];
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%s", temp);
		strcpy(arr[i].str, strchr(temp, '.')+1);
	}
	qsort(arr, N, sizeof(file), (int(*)(const void*, const void*))filecmp);
	for(i=0 ; i<N ; i++) {
		printf("%s ", arr[i].str);
		cou=0;	j=i;
		while(j<N) {
			if(!strcmp(arr[i].str, arr[j].str))
				cou++;
			else
				break;
			j++;
		}
		printf("%d\n", cou);
		i=j-1;
	}
	return 0;
}
