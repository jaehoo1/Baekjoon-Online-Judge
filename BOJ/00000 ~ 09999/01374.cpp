# include <cstdio>
# include <queue>
# include <algorithm>

using namespace std;

int main(void) {
	int N, n, s, e, cou=1;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> v;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++) {
		scanf("%d%d%d", &n, &s, &e);
		v.push_back({s, e});
	}
	sort(v.begin(), v.end());
	pq.push(v[0].second);
	for(int i=1 ; i<N ; i++) {
		if(pq.top()<=v[i].first)
			pq.pop();
		pq.push(v[i].second);
		if(pq.size()>cou)
			cou=pq.size();
	}
	printf("%d", cou);
	return 0;
}
