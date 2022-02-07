# include <cstdio>
# include <queue>
# include <cmath>

using namespace std;

struct cmp {
	bool operator()(int &a, int &b) {
		if(abs(a)==abs(b))
			return a>b;
		return abs(a)>abs(b);
	}
};

int main(void) {
	int N, num;
	priority_queue<int, vector<int>, cmp> pq;
	scanf("%d", &N);
	while(N--) {
		scanf("%d", &num);
		if(num)
			pq.push(num);
		else
			if(pq.empty())
				puts("0");
			else {
				int top=pq.top();
				pq.pop();
				printf("%d\n", top);
			}
	}
	return 0;
}
