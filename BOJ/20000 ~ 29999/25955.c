# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct {
	int tier, num;
	char c;
}difficulty;

int level(char c) {
	switch(c) {
		case 'B':
			return 0;
		case 'S':
			return 1;
		case 'G':
			return 2;
		case 'P':
			return 3;
		case 'D':
			return 4;
	}
}
int difcmp(const difficulty *a, const difficulty *b) {
	if(a->tier<b->tier)
		return -1;
	else if(a->tier>b->tier)
		return 1;
	else
		if(a->num>b->num)
			return -1;
		else if(a->num<b->num)
			return 1;
		else
			return 0;
}

int main(void) {
	int N, i, idx1=-1, idx2=-1;
	char c;
	bool issorted=true;
	difficulty arr[1000], sorted[1000];
	scanf("%d", &N);
	getchar();
	for(i=0 ; i<N ; i++) {
		scanf("%c%d", &arr[i].c, &arr[i].num);
		getchar();
		arr[i].tier=level(arr[i].c);
	}
	memcpy(sorted, arr, sizeof(difficulty)*N);
	qsort(sorted, N, sizeof(difficulty), (int(*)(const void*, const void*))difcmp);
	for(i=0 ; i<N ; i++)
		if(difcmp(&arr[i], &sorted[i])) {
			issorted=false;
			if(idx1==-1)
				idx1=i;
			else
				idx2=i;
		}
	if(issorted)
		puts("OK");
	else {
		puts("KO");
		printf("%c%d %c%d", arr[idx2].c, arr[idx2].num, arr[idx1].c, arr[idx1].num);
	}
	return 0;
}