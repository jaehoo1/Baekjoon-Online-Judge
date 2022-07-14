# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
	int N, index[100000], ptr;
	pair<int, int> AB[100000];
	bool isLCS[100000]={false, };
	vector<int> v;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		scanf("%d%d", &AB[i].first, &AB[i].second);
	sort(AB, AB+N);
	v.push_back(AB[0].second);
	index[0]=0;
	for(int i=1 ; i<N ; i++) {
		if(v.back()<AB[i].second) {
			index[i]=v.size();
			v.push_back(AB[i].second);
		} else {
			vector<int>::iterator iter=lower_bound(v.begin(), v.end(), AB[i].second);
			*iter=AB[i].second;
			index[i]=iter-v.begin();
		}
	}
	ptr=v.size()-1;
	for(int i=N-1 ; i>=0 ; i--)
		if(ptr==index[i]) {
			ptr--;
			isLCS[i]=true;
		}
	printf("%d\n", N-v.size());
	for(int i=0 ; i<N ; i++)
		if(!isLCS[i])
			printf("%d\n", AB[i].first);
	return 0;
}