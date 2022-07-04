# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

bool cmp(const int &a, const int &b) { return a>b; }

int main(void) {
	int N, A[1000], left, right, max=0;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		scanf("%d", &A[i]);
	for(int i=0 ; i<N ; i++) {
		vector<int> v;
		left=right=0;
		v.push_back(A[0]);
		for(int j=1 ; j<i ; j++)
			if(v.back()<A[j]&&A[j]<A[i])
				v.push_back(A[j]);
			else {
				vector<int>::iterator iter=lower_bound(v.begin(), v.end(), A[j]);
				*iter=A[j];
			}
		if(v[0]<A[i])
			left=v.size();
		v.clear();
		v.push_back(A[i]);
		for(int j=i+1 ; j<N ; j++)
			if(v.back()>A[j])
				v.push_back(A[j]);
			else {
				vector<int>::iterator iter=lower_bound(v.begin(), v.end(), A[j], cmp);
				*iter=A[j];
			}
		right=v.size();
		if(max<left+right)
			max=left+right;
	}
	printf("%d", max);
	return 0;
}