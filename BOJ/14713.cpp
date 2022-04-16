# include <cstdio>
# include <cstring>
# include <queue>

using namespace std;

typedef struct { char str[33]; }word;

int main(void) {
	int N;
	word w;
	queue<word> q[100];
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		while(true) {
			scanf("%s", w.str);
			q[i].push(w);
			if(getchar()=='\n')
				break;
		}
	}
	while(~scanf("%s", w.str)) {
		int i;
		for(i=0 ; i<N ; i++)
			if(!strcmp(w.str, q[i].front().str)) {
				q[i].pop();
				break;
			}
		if(i==N) {
			puts("Impossible");
			return 0;
		}				
	}
	for(int i=0 ; i<N ; i++)
		if(q[i].size()) {
			puts("Impossible");
			return 0;
		}
	puts("Possible");
	return 0;
}
