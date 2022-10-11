# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) { return a.second>b.second; }

int main(void) {
	int N, K, P;
	priority_queue<pair<int, int>> pq;
	vector<pair<int, int>> v;
	scanf("%d%d", &N, &K);
	while(N--) {
		scanf("%d", &P);
		pq.push({P, N});
	}
	while(K--) {
		if(pq.top().first<=100) {
			puts("impossible");
			return 0;
		}
		pq.push({pq.top().first-100, pq.top().second});
		pq.pop();
	}
	while(!pq.empty()) {
		v.push_back(pq.top());
		pq.pop();
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0 ; i<v.size() ; i++)
		printf("%d ", v[i].first);
	return 0;
}