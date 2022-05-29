# include <stdio.h>

typedef struct { int x, y; }pos;

void init(pos *p, const pos source) {
	p->x=source.x;
	p->y=source.y;
}

int main(void) {
	int N, i;
	pos UR, DL, p;
	scanf("%d", &N);
	scanf("%d%d", &p.x, &p.y);
	init(&UR, p);
	init(&DL, p);
	for(i=1 ; i<N ; i++) {
		scanf("%d%d", &p.x, &p.y);
		if(p.x>UR.x)
			UR.x=p.x;
		if(p.y>UR.y)
			UR.y=p.y;
		if(p.x<DL.x)
			DL.x=p.x;
		if(p.y<DL.y)
			DL.y=p.y;
	}
	printf("%d", (UR.x-DL.x)*(UR.y-DL.y));
	return 0;
}
