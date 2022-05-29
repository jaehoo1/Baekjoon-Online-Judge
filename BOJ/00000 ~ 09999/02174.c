# include <stdio.h>
# include <stdlib.h>

typedef struct {
	char x, y;
}pos;
typedef struct {
	pos p;
	char num, vec;
}robot;

char map[100][100]={0, };
int A, B;

void robotinit(robot *b, const int num) {
	int x, y;
	char v;
	b->num=num;
	scanf("%d%d", &x, &y);
	b->p.x=B-y;
	b->p.y=x-1;
	getchar();
	scanf("%c", &v);
	if(v=='N')b->vec=1;
	else if(v=='E')b->vec=2;
	else if(v=='S')b->vec=3;
	else if(v=='W')b->vec=4;
	map[b->p.x][b->p.y]=b->num;
}
void error(const robot *r) {
	int v=r->vec, x=r->p.x, y=r->p.y, Y;
	if((v==1&&!x)||(v==2&&y==A-1)||(v==3&&x==B-1)||(v==4&&!y))
		printf("Robot %d crashes into the wall", r->num);
	else {
		if(v==1)Y=map[x-1][y];
		else if(v==2)Y=map[x][y+1];
		else if(v==3)Y=map[x+1][y];
		else if(v==4)Y=map[x][y-1];
		printf("Robot %d crashes into robot %d", r->num, Y);
	}
	exit(0);
}
void left(robot *r) {
	r->vec--;
	if(!r->vec)r->vec=4;
}
void right(robot *r) {
	r->vec++;
	if(r->vec==5)r->vec=1;
}
void forward(robot *r) {
	if(r->vec==1) {
		if(!r->p.x)error(r);
		else if(map[r->p.x-1][r->p.y])error(r);
		map[r->p.x-1][r->p.y]=map[r->p.x][r->p.y];
		map[r->p.x][r->p.y]=0;
		r->p.x--;
	}
	else if(r->vec==2) {
		if(r->p.y==A-1)error(r);
		else if(map[r->p.x][r->p.y+1])error(r);
		map[r->p.x][r->p.y+1]=map[r->p.x][r->p.y];
		map[r->p.x][r->p.y]=0;
		r->p.y++;
	}
	else if(r->vec==3) {
		if(r->p.x==B-1)error(r);
		else if(map[r->p.x+1][r->p.y])error(r);
		map[r->p.x+1][r->p.y]=map[r->p.x][r->p.y];
		map[r->p.x][r->p.y]=0;
		r->p.x++;
	}
	else if(r->vec==4) {
		if(!r->p.y)error(r);
		else if(map[r->p.x][r->p.y-1])error(r);
		map[r->p.x][r->p.y-1]=map[r->p.x][r->p.y];
		map[r->p.x][r->p.y]=0;
		r->p.y--;
	}
}

int main(void) {
	robot arr[100];
	int N, M, num, i;
	char cmd;
	scanf("%d%d%d%d", &A, &B, &N, &M);
	for(i=0 ; i<N ; i++)
		robotinit(&arr[i], i+1);
	while(M--) {
		scanf("%d", &num);
		getchar();
		scanf("%c", &cmd);
		scanf("%d", &i);
		while(i--)
			if(cmd=='L')
				left(&arr[num-1]);
			else if(cmd=='R')
				right(&arr[num-1]);
			else if(cmd=='F')
				forward(&arr[num-1]);
	}
	puts("OK");
	return 0;
}
