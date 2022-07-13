# include <stdio.h>
# include <math.h>

typedef struct { int x, y; }pos;

double dist(pos a, pos b) { return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2)); }

int main(void) {
	int n, k, cou=0;
	pos safe, child;
	scanf("%d%d%d%d", &n, &k, &safe.x, &safe.y);
	while(n--) {
		scanf("%d%d", &child.x, &child.y);
		if(dist(safe, child)>k)
			cou++;
	}
	printf("%d", cou);
	return 0;
}