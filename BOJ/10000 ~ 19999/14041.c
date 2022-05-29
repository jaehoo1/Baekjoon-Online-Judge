# include <stdio.h>

typedef struct { int H, M; }time;

time cur, remain={2, 0};

int rushhour(void) {
	if(cur.H>=7&&cur.H<10)
		return 1;
	if(cur.H>=15&&cur.H<19)
		return 1;
	return 0;
}
void min10(void) {
	if(!remain.M) {
		remain.H--;
		remain.M=60;
	}
	remain.M-=10;
	if(rushhour())
		cur.M+=20;
	else
		cur.M+=10;
	if(cur.M>=60) {
		cur.M-=60;
		cur.H++;
	}
	if(cur.H==24)
		cur.H=0;
}

int main(void) {
	scanf("%d:%d", &cur.H, &cur.M);
	while(remain.H||remain.M)
		min10();
	printf("%02d:%02d", cur.H, cur.M);
	return 0;
}
