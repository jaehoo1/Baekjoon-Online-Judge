# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

int main(void) {
	int N, S, E, max=1;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		scanf("%d%d", &S, &E);
		v.push_back({S, E});
	}
	sort(v.begin(), v.end());
	pq.push(v[0].second);
	for(int i=1 ; i<N ; i++) {
		if(pq.top()<=v[i].first)
			pq.pop();
		pq.push(v[i].second);
		if(pq.size()>max)
			max=pq.size();
	}
	printf("%d", max);
	return 0;
}
