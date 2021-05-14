# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct {
	char name[21];
	int idx;
}poke;

int main(void) {
	int N, M, i, temp;
	char cmd[21];
    poke arr[100000], sorted[100000], *p;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++) {
		scanf("%s", arr[i].name);
		strcpy(sorted[i].name, arr[i].name);
		arr[i].idx=i;
		sorted[i].idx=i;
	}
	qsort(sorted, N, sizeof(poke), (int(*)(const void*, const void*))strcmp);
	while(M--) {
		temp=0;
		scanf("%s", cmd);
		if(cmd[0]>='0'&&cmd[0]<='9')
			sscanf(cmd, "%d", &temp);
		if(temp)
			puts(arr[temp-1].name);
		else {
			p=(poke*)bsearch(cmd, sorted, N, sizeof(poke), (int(*)(const void*, const void*))strcmp);
			printf("%d\n", p->idx+1);
		}
	}
	return 0;
}
