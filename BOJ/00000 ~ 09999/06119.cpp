# include <cstdio>
# include <deque>

using namespace std;

int main(void) {
	int S, K, num=0;
	char cmd, direction;
	deque<int> dq;
	scanf("%d", &S);
	getchar();
	while(S--) {
		scanf("%c %c", &cmd, &direction);
		getchar();
		if(cmd=='A') {
			if(direction=='L')
				dq.push_front(++num);
			else if(direction=='R')
				dq.push_back(++num);
		} else if(cmd=='D') {
			scanf("%d", &K);
			getchar();
			while(K--) {
				if(direction=='L')
					dq.pop_front();
				else if(direction=='R')
					dq.pop_back();
			}
		}
	}
	while(!dq.empty()) {
		printf("%d\n", dq.front());
		dq.pop_front();
	}
	return 0;
}