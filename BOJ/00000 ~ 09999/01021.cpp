# include <cstdio>
# include <deque>

using namespace std;

int main(void) {
	int N, M, arr[50], front, back, cou=0;
	deque<int> d;
	scanf("%d%d", &N, &M);
	for(int i=1 ; i<=N ; i++)
		d.push_back(i);
	for(int i=0 ; i<M ; i++)
		scanf("%d", &arr[i]);
	for(int i=0 ; i<M ; i++) {
		for(front=0 ; front<N-i ; front++)
			if(d[front]==arr[i])
				break;
		for(back=0 ; back<N-i ; back++)
			if(d[N-i-back-1]==arr[i])
				break;
		if(front<back+1) {
			for(int j=0 ; j<front ; j++) {
				d.push_back(d.front());
				d.pop_front();
			}
			d.pop_front();
			cou+=front;
		} else {
			for(int j=0 ; j<=back ; j++) {
				d.push_front(d.back());
				d.pop_back();
			}
			d.pop_front();
			cou+=back+1;
		}
	}
	printf("%d", cou);
	return 0;
}
