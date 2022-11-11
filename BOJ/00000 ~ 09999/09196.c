# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int h, w, d;
}rect;

int rectcmp(const rect *a, const rect *b) {
	if(a->d<b->d)
		return -1;
	else if(a->d>b->d)
		return 1;
	else
		if(a->h<b->h)
			return -1;
		else if(a->h>b->h)
			return 1;
		else
			return 0;
}

int main(void) {
	rect arr[11175], r, *ptr;
	int h, w, i, j, pos=0;
	for(i=1 ; i<=150 ; i++)
		for(j=i+1 ; j<=150 ; j++) {
			arr[pos].h=i;
			arr[pos].w=j;
			arr[pos++].d=i*i+j*j;
		}
	qsort(arr, 11175, sizeof(rect), (int(*)(const void*, const void*))rectcmp);
	while(scanf("%d%d", &h, &w)) {
		if(!h&&!w)
			break;
		r.h=h;
		r.w=w;
		r.d=h*h+w*w;
		ptr=(rect*)bsearch(&r, arr, 11175, sizeof(rect), (int(*)(const void*, const void*))rectcmp)+1;
		printf("%d %d\n", ptr->h, ptr->w);
	}
	return 0;
}