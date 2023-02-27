# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct { char time[9], team; }racer;

int racercmp(const racer *a, const racer *b) { return strcmp(a->time, b->time); }

int main(void) {
	racer arr[8];
	int i, score_R=0, score_B=0, scores[8]={10, 8, 6, 5, 4, 3, 2, 1};
	for(i=0 ; i<8 ; i++)
		scanf("%s %c", arr[i].time, &arr[i].team);
	qsort(arr, 8, sizeof(racer), (int(*)(const void*, const void*))racercmp);
	for(i=0 ; i<8 ; i++)
		if(arr[i].team=='R')
			score_R+=scores[i];
		else if(arr[i].team=='B')
			score_B+=scores[i];
	puts(score_R>score_B?"Red":"Blue");
	return 0;
}