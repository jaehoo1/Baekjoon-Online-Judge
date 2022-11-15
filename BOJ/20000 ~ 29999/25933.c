# include <stdio.h>
# include <stdbool.h>

typedef struct { int g, s, b; }medals;

bool count(medals us, medals ru) { return us.g+us.s+us.b>ru.g+ru.s+ru.b; }
bool color(medals us, medals ru) {
	if(us.g>ru.g)
		return true;
	else if(us.g<ru.g)
		return false;
	else
		if(us.s>ru.s)
			return true;
		else if(us.s<ru.s)
			return false;
		else
			if(us.b>ru.b)
				return true;
			else if(us.b<ru.b)
				return false;
			else
				return false;
}

int main(void) {
	int N;
	medals us, ru;
	scanf("%d", &N);
	while(N--) {
		scanf("%d%d%d%d%d%d", &us.g, &us.s, &us.b, &ru.g, &ru.s, &ru.b);
		printf("%d %d %d %d %d %d\n", us.g, us.s, us.b, ru.g, ru.s, ru.b);
		if(count(us, ru)&&color(us, ru))
			puts("both");
		else if(count(us, ru))
			puts("count");
		else if(color(us, ru))
			puts("color");
		else
			puts("none");
		puts("");
	}
	return 0;
}